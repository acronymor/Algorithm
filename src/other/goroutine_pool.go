package other

import (
	"fmt"
	"time"
)

var ErrorScheduleTimeout = fmt.Errorf("schedule error: timeout")

type Pool struct {
	sem  chan struct{}
	work chan func()
}

func NewPool(size, queue, spawn int) *Pool {
	if spawn <= 0 && queue > 0 {
		panic("dead queue configuration detected")
	}

	if spawn > size {
		panic("spawn > works")
	}

	p := &Pool{
		sem:  make(chan struct{}, size),
		work: make(chan func(), queue),
	}

	for i := 0; i < spawn; i++ {
		p.sem <- struct{}{}
		go p.worker(func() {})
	}

	return p
}

func (p *Pool) worker(task func()) {
	defer func() { <-p.sem }()

	task()

	for work := range p.work {
		work()
	}
}

func (p *Pool) schedule(task func(), timeout <-chan time.Time) error {
	select {
	case <-timeout:
		return ErrorScheduleTimeout
	case p.work <- task:
		return nil
	case p.sem <- struct{}{}:
		go p.worker(task)
		return nil
	}
}

func (p *Pool) Schedule(task func()) error {
	return p.schedule(task, nil)
}

func (p *Pool) ScheduleTimeout(task func(), timeout time.Duration) error {
	return p.schedule(task, time.After(timeout))
}

func (p *Pool) Close() {
	close(p.work)
	close(p.sem)
}
