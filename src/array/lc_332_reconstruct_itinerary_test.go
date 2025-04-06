package array

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFindItinerary(t *testing.T) {
	var tickets [][]string = [][]string{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}}
	var res []string = findItinerary(tickets)
	var expected []string = []string{"JFK", "MUC", "LHR", "SFO", "SJC"}
	assert.ElementsMatch(t, expected, res)

	tickets = [][]string{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}}
	res = findItinerary(tickets)
	expected = []string{"JFK", "SFO", "ATL", "JFK", "ATL", "SFO"}
	assert.ElementsMatch(t, expected, res)
}
