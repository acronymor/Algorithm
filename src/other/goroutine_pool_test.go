package other

import (
	"fmt"
	"testing"
)

func BenchmarkGoRoutinePool(t *testing.B) {
	pool := NewPool(1024, 1024, 1024)
	defer pool.Close()

	for i := 0; i < t.N; i++ {
		err := pool.Schedule(func() {
			fmt.Println("Go, Hello world ->", i)
		})
		if err != nil {
			fmt.Println("ERROR: ", err)
		}
	}

}
