// we use fmt for formatting strings and output strings
// to export something from package , write it its first word capital
package main

import "fmt"

// var someVar = "this can be used outside main"

// but the colon one wont
// anotherVar := "this wont work here"

func main() {
	// everything after fmt starts with capital case
	fmt.Println("hello there mate")

	// cannot use single quotes
	var name string = "Akshat"
	var infereString = "type inference is there in go"
	// default value of string is empty
	var emptyStr string
	fmt.Println(name, infereString, emptyStr)

	// without var keyword
	declareMe := "the colon is only used during declaration"
	// red swiggly lines if variable declared but not used
	fmt.Println(declareMe)

	// int variables
	var ageOne int = 20
	var ageTwo = 30
	ageThree := 40

	fmt.Print(ageOne, ageTwo, ageThree)

	// bits & memory
	// var numOne int8 = 25
	// var numTwo int8 = 128 // too large a number for 8-bit
	// var numTwu uint = -25 // unsigned ints cannot be negative
	// var numTwu uint16 = 678 // unsigned ints can also have ranges (0-255 for 8)
	// fmt.Print(numOne, numTwo, numTwu )

	var scoreOne float32 = 25.98
	// float64 has a better precision
	var scoreTwo float64 = 1965385877.5
	var scoreThree = 1.5 // inferred as float64

	fmt.Print(scoreOne, scoreTwo, scoreThree)

	age := 35
	newname := "shaun"

	// here go adds spaces betwwen them itself
	fmt.Println("my age is", age, "and my name is", newname)

	// Printf (formatted string), %_ = format specifier
	fmt.Printf("my age is %v and my name is %v \n", age, name) // %v = value in default format
	fmt.Printf("my age is %q and my name is %q \n", age, name) // %q = quotes
	fmt.Printf("age is of type %T \n", age)                    // %T is the type
	fmt.Printf("you scored %f points! \n", 225.55)             // %f = float format
	fmt.Printf("you scored %0.1f points! \n", 225.55)          // %0.2f = float with 2 decimal points
	fmt.Printf("you scored %0.1v points! \n", 225.55)          // doest't work

	// Sprintf (save formatted strings)
	var str = fmt.Sprintf("my age is %v and my name is %v \n", age, name)
	fmt.Println("the saved string is:", str)
}
