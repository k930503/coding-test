func solution(sequence []int, k int) []int {
    
    left := 0
	right := 0
    sum := sequence[0]
    length := len(sequence)
    answer := []int{left, right}
    
    for right < len(sequence) {
        
        if sum < k {
            right++
            if right < len(sequence) {
                sum += sequence[right]
            }
        } else if sum > k {
            sum -= sequence[left]
            left++
        } else {
            interval := right - left
            if length > interval {
                length = interval
                answer[0] = left
                answer[1] = right
            }
            
            right++
            if right < len(sequence) {
                sum += sequence[right]
            }

            sum -= sequence[left]
            left++
        }
    }
    return answer
}