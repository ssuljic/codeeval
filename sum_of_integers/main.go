package main

import "fmt"
import "log"
import "bufio"
import "os"
import "strconv"

func main() {
    file, err := os.Open(os.Args[1])
    if err != nil {
        log.Fatal(err)
    }
    defer file.Close()
    scanner := bufio.NewScanner(file)
    sum := 0
    for scanner.Scan() {
        i, err := strconv.Atoi(scanner.Text())
        if err != nil {
            log.Fatal(err)
        }
        sum += i
    }
    fmt.Print(sum)
}