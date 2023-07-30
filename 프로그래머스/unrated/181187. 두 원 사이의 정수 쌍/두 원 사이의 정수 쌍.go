package main

import "math"

func solution(r1 int, r2 int) int64 {

	var count int64 = 0
	for i := 1; i <= r2; i++ {
		max := math.Floor(math.Sqrt(float64(r2 * r2 - i * i)))
		min := float64(0)
		if i < r1 {
			min = math.Ceil(math.Sqrt(float64(r1 * r1 - i * i)))
		}

		count += int64(max - min + 1)
	}

	return count * 4
}