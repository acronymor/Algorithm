package other

import (
	"fmt"
	"testing"
	"time"
)

func BenchmarkGoroutineCount(t *testing.B) {
	for i := 0; i < t.N; i++ {
		s := time.Now()
		CountGoRoutine1()
		fmt.Println("Coroutine1 Done, duration=", time.Since(s))
	}

	for i := 0; i < t.N; i++ {
		s := time.Now()
		CountGoRoutine2()
		fmt.Println("Coroutine2 Done, duration=", time.Since(s))
	}

	for i := 0; i < t.N; i++ {
		s := time.Now()
		CountGoRoutine3()
		fmt.Println("Coroutine3 Done, duration=", time.Since(s))
	}
}
