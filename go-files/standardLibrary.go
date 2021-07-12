package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	greeting := "hello there friends!"

	fmt.Println(strings.Contains(greeting, "hello"))
	fmt.Println(strings.Contains(greeting, "bye"))
	fmt.Println(strings.ReplaceAll(greeting, "hello", "hi")) // just returns a new string, original remains same
	fmt.Println(strings.ToUpper(greeting))                   // just returns a new string, original remains same
	fmt.Println(strings.Index(greeting, "ll"))
	fmt.Println(strings.Split(greeting, " ")) // just returns a new array

	// the original value is unchanged
	fmt.Println("original string value =", greeting)

	ages := []int{45, 20, 35, 30, 75, 60, 50, 25}

	sort.Ints(ages)
	fmt.Println(ages)

	index := sort.SearchInts(ages, 30) // finds the index a sorted array not in a unsorted array
	// if we search for a number that is non existent in the array then it returns the last index
	fmt.Println(index)

	names := []string{"yoshi", "mario", "peach", "bowser", "luigi"}

	sort.Strings(names)
	fmt.Println(names)

	fmt.Println(sort.SearchStrings(names, "bowser"))

}
