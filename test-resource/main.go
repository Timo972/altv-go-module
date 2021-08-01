package main

import "C"
import "fmt"


func main() { }

//export StartResource
func StartResource() {
	fmt.Println("---------> Hello from go resource")
}