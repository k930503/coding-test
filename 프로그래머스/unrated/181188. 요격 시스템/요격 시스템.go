import "sort"

func solution(targets [][]int) int {
	count := 0;

	sort.Slice(targets, func(i, j int) bool {
		if targets[i][1] == targets[j][1] {
			return targets[i][0] < targets[j][0]
		}
        return targets[i][1] < targets[j][1]
    })

	cut := -1

	for i := 0; i < len(targets); i++ {
		if targets[i][0] >= cut {
			cut = targets[i][1]
			count++
		} 
	}
    return count
}