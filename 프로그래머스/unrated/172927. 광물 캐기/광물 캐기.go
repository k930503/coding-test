import (
    "fmt"
    "sort"
)

func solution(picks []int, minerals []string) int {
    max := (picks[0] + picks[1] + picks[2]) * 5
    
    if max >= len(minerals) {
        max = len(minerals) 
    }
    
    size := max / 5
    if max % 5 > 0 {
        size++
    }
    var fatigues = make([][3]int, size)
    index := 0
    fmt.Println("fff: ", fatigues);
    
    for i := 0; i < max; i++ {
        if minerals[i] == "diamond" {
            fatigues[index][0]++
        } else if minerals[i] == "iron" {
            fatigues[index][1]++
        } else {
            fatigues[index][2]++
        }
        
        if i % 5 == 4 { 
            index++
        }
    }
    
    fmt.Println("aa: ", fatigues);
    
    sort.Slice(fatigues, func(i, j int) bool {
        if fatigues[i][0] > fatigues[j][0] {
            return true
        } else if fatigues[i][0] < fatigues[j][0] {
            return false
        } else {
            if fatigues[i][1] > fatigues[j][1] {
                return true
            } else if fatigues[i][1] < fatigues[j][1] {
                return false
            } else {
                return true
            }
        }
        
    })
    fmt.Println("bb: ", fatigues);
    
    result := 0
    index = 0
    for i := 0; i < len(picks); i++ {
        for j := 0; j < picks[i] && index < len(fatigues); j++ {
            if i == 0 {
                result += fatigues[index][0] + fatigues[index][1] + fatigues[index][2]
            } else if i == 1 {
                result += (fatigues[index][0] * 5) + fatigues[index][1] + fatigues[index][2]
            } else {
                result += (fatigues[index][0] * 25) + (fatigues[index][1] * 5) + fatigues[index][2]
            }
            index++
        }
    }
    
    return result
}