import (
	"sort"
	"strconv"
	"time"
)

type blockedAssignment struct {
    subject string
    remainTime float64
}

func solution(plans [][]string) []string {
    
    layout := "15:04"
    sort.Slice(plans, func(i, j int) bool {
        left, _ := time.Parse(layout, plans[i][1])
        right, _ := time.Parse(layout, plans[j][1])
        if left.Before(right) {
            return true
        }
        return false
    })

    result := make([]string, 0, len(plans))
    stack := [1000]blockedAssignment{}
    top := -1
    index := 0
    
    for top > -1 || index < len(plans) {
        
        currentSubject := ""
        afterTimeCurrentWork := time.Time{}
        nextWorkTime := time.Time{}

        if index < len(plans) {
            currentSubject = plans[index][0]
            currentWorkTime, _ := time.Parse(layout, plans[index][1])
            temp, _ := strconv.Atoi(plans[index][2])
            currentWorkDuration := time.Duration(temp) * time.Minute
            afterTimeCurrentWork = currentWorkTime.Add(currentWorkDuration)
            index++
            
            if index < len(plans) {
                nextWorkTime, _ = time.Parse(layout, plans[index][1])
            }
        }

        if nextWorkTime.IsZero() {
            if afterTimeCurrentWork.IsZero() {
                if top > -1 {
                    // 밀린 업무 처리
                    result = append(result, stack[top].subject)
                    top--
                }
            } else {
                // 현재 업무 처리
                result = append(result, currentSubject)
            }
        } else {
            if afterTimeCurrentWork.After(nextWorkTime) {
                // 현재 업무를 할 수 있는 만큼만 하고 밀어두기
                top++
                stack[top] = blockedAssignment{ currentSubject, (afterTimeCurrentWork.Sub(nextWorkTime).Minutes()) }
                //fmt.Println("ccC: ", (afterTimeCurrentWork.Sub(nextWorkTime)).Minutes())
            } else if afterTimeCurrentWork.Equal(nextWorkTime) {
                // 현재 업무 딱 가능
                result = append(result, currentSubject)
            } else {
                // 현재 업무 진행 후, 남는 시간 밀어둔 업무 처리
                result = append(result, currentSubject)
                remainTime := nextWorkTime.Sub(afterTimeCurrentWork).Minutes()
                for remainTime > 0 && top > -1 {
                    if remainTime >= stack[top].remainTime {
                        result = append(result, stack[top].subject)
                        remainTime -= stack[top].remainTime
                        top--
                    } else {
                        stack[top].remainTime -= remainTime
                        remainTime = 0
                    }
                }
            }
        }
    }

    return result
}