package main

import ("fmt"
       "strconv")

func main() {
    var s1 string
    var a string
    fmt.Scan(&s1, &a)
    length, _ := strconv.Atoi(a)
    for i := 0; i < length; i++ {
        fmt.Print(s1)
    }
}