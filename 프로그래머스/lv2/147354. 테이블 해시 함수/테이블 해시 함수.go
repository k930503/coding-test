import (
	"sort"
)

type wrap struct {
	s []int
}

func solution(data [][]int, col int, row_begin int, row_end int) int {

	wrapSlice := make([]wrap, 0)

	for i := 0; i < len(data); i++ {
		w := wrap{make([]int, 0)}
		for j := 0; j < len(data[i]); j++ {
			w.s = append(w.s, data[i][j])
		}
		wrapSlice = append(wrapSlice, w)
	}

	sort.Slice(wrapSlice, func(i, j int) bool {
		if wrapSlice[i].s[col-1] == wrapSlice[j].s[col-1] {
			return wrapSlice[i].s[0] > wrapSlice[j].s[0]
		}
		return wrapSlice[i].s[col-1] < wrapSlice[j].s[col-1]
	})

	s_iSlice := make([]int, 0)
	for i := row_begin - 1; i < row_end; i++ {
		s_i := 0
		for j := 0; j < len(wrapSlice[i].s); j++ {
			s_i += wrapSlice[i].s[j] % (i + 1)
		}
		s_iSlice = append(s_iSlice, s_i)
	}

	result := s_iSlice[0]
	for i := 1; i < len(s_iSlice); i++ {
		result = result ^ s_iSlice[i]
	}
	return result
}