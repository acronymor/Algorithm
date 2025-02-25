package other

import (
	"fmt"
	"sync"
)

func printNumber(ch chan bool, wg *sync.WaitGroup) {
	defer wg.Done()
	numbers := []int{1, 2, 3, 4, 5}

	for _, num := range numbers {
		<-ch
		fmt.Print(num, " ")
		ch <- true
	}
}

func printLetter(ch chan bool, wg *sync.WaitGroup) {
	ch <- true

	defer wg.Done()
	letters := []string{"a", "b", "c", "d", "e"}

	for _, letter := range letters {
		<-ch
		fmt.Print(letter, " ")
		ch <- true
	}
}

func printLetterAndNumber() {
	ch := make(chan bool, 1)
	var wg sync.WaitGroup
	wg.Add(2)

	go printLetter(ch, &wg)
	go printNumber(ch, &wg)

	wg.Wait()
	close(ch)
}
