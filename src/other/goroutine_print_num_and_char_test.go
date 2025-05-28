package other

import "testing"

func BenchmarkPrintLetterAndNumber(t *testing.B) {
	for i := 0; i < t.N; i++ {
		printLetterAndNumber()
	}
}
