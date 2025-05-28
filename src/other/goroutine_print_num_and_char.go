package other

import (
	"fmt"
	"sync"
)

func printLetterAndNumber() {
	chN := make(chan bool, 1)
	chC := make(chan bool, 1)
	defer close(chN)
	defer close(chC)

	wg := sync.WaitGroup{}
	wg.Add(2)

	res := make(chan any)
	chN <- true

	go func() {
		defer wg.Done()
		var nums []int = []int{1, 2, 3, 4, 5, 6, 7, 8, 9}

		for _, num := range nums {
			<-chN
			res <- num
			chC <- true
		}
	}()

	go func() {
		defer wg.Done()
		var letters []byte = []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'}

		for _, letter := range letters {
			<-chC
			res <- string(letter)
			chN <- true
		}
	}()

	go func() {
		wg.Wait()
		close(res)
	}()

	for item := range res {
		fmt.Printf("%v ", item)
	}
	fmt.Println()
}
