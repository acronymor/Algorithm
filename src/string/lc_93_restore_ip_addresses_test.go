package string

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestRestoreIpAddresses(t *testing.T) {
	var s string = "25525511135"
	var res []string = restoreIpAddresses(s)
	assert.Equal(t, "255.255.11.135", res[0])
	assert.Equal(t, "255.255.111.35", res[1])

	s = "0000"
	res = restoreIpAddresses(s)
	assert.Equal(t, "0.0.0.0", res[0])

	s = "101023"
	res = restoreIpAddresses(s)
	assert.Equal(t, "1.0.10.23", res[0])
	assert.Equal(t, "1.0.102.3", res[1])
	assert.Equal(t, "10.1.0.23", res[2])
	assert.Equal(t, "10.10.2.3", res[3])
	assert.Equal(t, "101.0.2.3", res[4])
	fmt.Println(res)
}
