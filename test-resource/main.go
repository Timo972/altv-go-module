package main

import "C"
import "fmt"

func main() {}

//export InitResource
func InitResource() {
	fmt.Println("---------> Hello from go resource")
}

