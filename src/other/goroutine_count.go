package other

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func CountGoRoutine1() {
	work := func(c, t int) {
		n := rand.Intn(10)
		fmt.Printf("coroutine=%d, task=%d, sleep=%d\n", c, t, n)
		time.Sleep(time.Duration(n) * time.Second)
	}

	m, n := 10, 5

	tasks := make(chan int, m)
	for i := 0; i < m; i++ {
		tasks <- m - i
	}
	close(tasks)

	wg := sync.WaitGroup{}
	for i := 0; i < n; i++ {
		wg.Add(1)
		go func(c int) {
			defer wg.Done()

			for {
				task, ok := <-tasks
				if !ok {
					break
				}
				work(c, task)
			}
		}(i)
	}

	wg.Wait()
}

func CountGoRoutine2() {
	work := func(c, t int) {
		n := rand.Intn(10)
		fmt.Printf("coroutine=%d, task=%d, sleep=%d\n", c, t, n)
		time.Sleep(time.Duration(n) * time.Second)
	}

	var tasks []int = []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	wg := sync.WaitGroup{}
	wg.Add(len(tasks))

	var m int = 5
	var limit = make(chan int, m)
	defer close(limit)

	// 如果出现了异常，仍继续执行
	for i, task := range tasks {
		limit <- 1

		go func(coroutine int) {
			defer wg.Done()
			work(coroutine, task)
			<-limit
		}(i % m)
	}

	wg.Wait()
}

func CountGoRoutine3() {
	work := func(c, t int) error {
		n := rand.Intn(t)
		fmt.Printf("coroutine=%d, task=%d, sleep=%d\n", c, t, n)
		time.Sleep(time.Duration(n) * time.Second)

		if c == 1 {
			return fmt.Errorf("I don't kown what happed")
		}

		return nil
	}

	var tasks []int = []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	wg := sync.WaitGroup{}
	wg.Add(len(tasks))

	var m int = 5
	var limit = make(chan int, m)
	defer close(limit)

	done := make(chan bool, 1)

	// 如果出现了异常，就立即终止
	for i, task := range tasks {
		select {
		case limit <- 1:
			go func(coroutine int) {
				defer wg.Done()
				err := work(coroutine, task)
				if err != nil {
					done <- true
					close(done)
				}
				<-limit
			}(i % m)
		case doing := <-done:
			fmt.Println("ERROR, doing=", doing)
			return
		}
	}

	wg.Wait()
}
