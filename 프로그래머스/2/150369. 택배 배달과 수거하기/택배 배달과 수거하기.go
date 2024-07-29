
func solution(cap int, n int, deliveries []int, pickups []int) int64 {
	totalRemainDeleveryCnt := 0
	for i := 0; i < len(deliveries); i++ {
		totalRemainDeleveryCnt += deliveries[i]
	}

	totalRemainPickupCnt := 0
	for i := 0; i < len(deliveries); i++ {
		totalRemainPickupCnt += pickups[i]
	}

	var distance int64 = 0
	for totalRemainDeleveryCnt != 0 || totalRemainPickupCnt != 0 {
		//fmt.Println("n: ", n)
		dAmount := 0
		pAmount := 0
		if totalRemainDeleveryCnt >= cap {
			dAmount = cap
		} else {
			dAmount = totalRemainDeleveryCnt
		}

		if totalRemainPickupCnt >= cap {
			pAmount = cap
		} else {
			pAmount = totalRemainPickupCnt
		}

		totalRemainDeleveryCnt -= dAmount
		totalRemainPickupCnt -= pAmount

		for len(deliveries) > 1 && deliveries[len(deliveries)-1] == 0 {
			deliveries = deliveries[0 : len(deliveries)-1]
		}
		dEnd := len(deliveries)

		for len(pickups) > 1 && pickups[len(pickups)-1] == 0 {
			pickups = pickups[0 : len(pickups)-1]
		}
		pEnd := len(pickups)

		idx := dEnd - 1
		for dAmount != 0 {
			if deliveries[idx] > dAmount {
				deliveries[idx] -= dAmount
				break
			} else if deliveries[idx] == dAmount {
				deliveries[idx] = 0
				dAmount = 0
				deliveries = deliveries[0:idx]
				idx--
			} else if deliveries[idx] < dAmount {
				dAmount -= deliveries[idx]
				deliveries = deliveries[0:idx]
				idx--
			}
		}

		idx = pEnd - 1
		for pAmount != 0 {
			if pickups[idx] > pAmount {
				pickups[idx] -= pAmount
				break
			} else if pickups[idx] == pAmount {
				pickups[idx] = 0
				pAmount = 0
				pickups = pickups[0:idx]
				idx--
			} else if pickups[idx] < pAmount {
				pAmount -= pickups[idx]
				pickups = pickups[0:idx]
				idx--
			}
		}

		if dEnd > pEnd {
			distance += int64(dEnd * 2)
		} else {
			distance += int64(pEnd * 2)
		}

		// fmt.Println("d: ", dEnd, "p: ", pEnd)
		// fmt.Println("remadele: ", totalRemainDeleveryCnt, "remainpic: ", totalRemainPickupCnt)

	}

	return distance
}
