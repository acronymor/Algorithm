package other

import (
	"fmt"
	"sync"
)

func send(ch chan<- int, wg *sync.WaitGroup) {
	defer wg.Done()
	defer close(ch)

	for i := 0; i < 10; i++ {
		ch <- i
	}

}

func receive(ch <-chan int, wg *sync.WaitGroup) {
	defer wg.Done()

	for {
		num, ok := <-ch
		if !ok {
			break
		}
		fmt.Printf("%d ", num)
	}
}

func sendReceiveRun() {
	ch := make(chan int)

	var wg sync.WaitGroup
	wg.Add(2)

	go send(ch, &wg)
	go receive(ch, &wg)

	wg.Wait()
}
