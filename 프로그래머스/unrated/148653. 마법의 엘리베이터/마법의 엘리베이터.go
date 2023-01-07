func solution(storey int) int {

	slice := make([]int, 0)

	for storey != 0 {
		slice = append(slice, storey%10)
		storey /= 10
	}

	if len(slice) == 1 {
		if slice[0] <= 5 {
			return slice[0]
		}
		return 10 - slice[0]
	}

	stone := 0
	for i := 1; i < len(slice); i++ {
		if slice[i-1] == 5 {
			stone += 5
			if slice[i] >= 5 {
				slice[i]++
			}
		} else if slice[i-1] > 5 {
			stone += 10 - slice[i-1]
			slice[i]++
		} else {
			stone += slice[i-1]
		}
	}

	if slice[len(slice)-1] <= 5 {
		stone += slice[len(slice)-1]
	} else {
		stone += 11 - slice[len(slice)-1]
	}

	return stone
}
