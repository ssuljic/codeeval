package main

import "fmt"
import "log"
import "bufio"
import "os"
import "regexp"
import "strings"

func main() {
	file, err := os.Open(os.Args[1])
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	r, _ := regexp.Compile("[a-zA-Z]+")

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		words := r.FindAllString(scanner.Text(), -1)
		sentence := strings.Join(words[:], " ")
		fmt.Println(strings.ToLower(sentence))
	}
}
