package main

import "fmt"
import "log"
import "bufio"
import "os"
import "strings"
import "regexp"

func main() {
  file, err := os.Open(os.Args[1])
  if err != nil {
    log.Fatal(err)
  }
  defer file.Close()

  scanner := bufio.NewScanner(file)
  for scanner.Scan() {
    parts := strings.Split(scanner.Text(), ",")
    r, _ := regexp.Compile("[" + strings.Trim(parts[1], " ") + "]")
    fmt.Println(r.ReplaceAllString(parts[0], ""))
  }
}
