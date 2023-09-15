#include "HW1_CS2413.h"
//
// ========================================
// Assignment 1: C++ Programming
// ========================================
//
// In this assignment, we will implement
// a Student class and a University class.
//
// The Student class has two private member
// variables and five member functions (not
// counting the constructor). Their designs
// are explained in the template below.
//
// The University class has one private member
// variable and four member functions. Their
// designs are explained in the template below.
//
// In the template, you will see two types of
// sections: "Task" and "Test". A "Task" section
// is where you need to implement something,
// and a "Test" section is testing your implementation
// (you don't need to do anything in this section).
//
// For all print functions, only print the value
// and do not add any additional character
// such as space or change line. For example,
// if you are asked to print the value of x,
// write "cout << x;" instead of "cout << x << endl;"
//
//
// ======= Task 1 =======
// Complete the header files
// ......
// ......
// 

#include <iostream>; 
//imports the functions we use input and output text

using namespace std;
//makes calling those functions much easier

// 
// ......
// === End of Task 1 ====
// ======= Task 2 =======
// Design and implement all member functions of the
// following two classes: Student and University.
// All member functions must be implemented outside
// the class definitions.
//
class Student {
public:
	void set_SID(int x); // It assigns x to SID.
	void prt_SID(); // It prints SID.
	void set_GPA(float y);// It assigns y to GPA.
	float get_GPA(); // It returns the GPA 
	void prt_GPA(); // It prints GPA.
	void reset(); // It resets SID and GPA to -1.
	Student(); // Constructor. It initializes
	// both SID and GPA to -1.
private:
	int SID; // It holds a student's ID.
	float GPA; // It holds a student's GPA.
};

class University {
public:
	void set_Stu(Student x[]);// It assigns x to Sooner.
	float GPA_Mean(); // It prints the mean GPA of the five students held by Sooner[5].
	float GPA_Max(); // It prints the max GPA of these five students.
	float GPA_Min(); // It prints the min GPA of these five students.
	University(); // Constructor. Initialize all student SID and GPA to - 1.
	// Note: The above three functions must be implemented by yourself
	// and not called from existing mean, max or min functions.
private:
	Student Sooner[5]; // It holds the records of five students.
};

//assigns x to SID
void Student::set_SID(int x) {
	SID = x;
}

//outputs SID
void Student::prt_SID() {
	cout << SID;
}

//assigns y to GPA
void Student::set_GPA(float y) {
	GPA = y;
}

//outputs GPA
void Student::prt_GPA() {
	cout << GPA;
}

//returns the float value of the GPA
float Student::get_GPA() {
	return GPA;
}

//resets SID and GPA to their initial values
void Student::reset() {
	SID = -1;
	GPA = -1.0;
}

//Constructor for a Student class
Student::Student() {
	reset();
}

//sets the student array items equal to the inputted array
void University::set_Stu(Student x[]) {
	//iterates over x, making sure not to outOfBounds
	//additionally, we don't want to overwhelm our 5-size array
	for (int i = 0; i < 5 && i < sizeof(x); i++) {
		Sooner[i] = x[i];
	}
}

//returns the average of all 
float University::GPA_Mean() {
	float totalGPA = 0;
	int totalIt = 0;

	//total of addition / total of items = average of items
	for (int i = 0; i < 5; i++) {
		if (Sooner[i].get_GPA() == -1) { break; }
		totalGPA += Sooner[i].get_GPA();
		totalIt++;
	}

	float avg = totalGPA / totalIt;

	cout << avg;
	return avg;
}

//returns the greatest GPA value out of the entire array
float University::GPA_Max() {
	//var to store max
	float maxGPA = 0.0;

	//iterate over all the items
	for (int i = 0; i < 5; i++) {
		//only reason is if it's the end of the list; a 'null' student. Easier to break
		if (Sooner[i].get_GPA() == -1) { break; }

		//if the current iteration's value is greater than the variable's value, then we store the current it's value over the variable, and continue over the rest of the list
		if (Sooner[i].get_GPA() > maxGPA) { maxGPA = Sooner[i].get_GPA(); }
	}

	cout << maxGPA;
	return maxGPA;
}

//returns the lowest GPA value out of the entire array
float University::GPA_Min() {
	//variable to store minimum
	float minGPA = 5.0;

	//same logic as last func, just with '<' instead of '>'
	for (int i = 0; i < 5 && i < sizeof(Sooner); i++) {
		if (Sooner[i].get_GPA() == -1) { break; }

		if (Sooner[i].get_GPA() < minGPA) { minGPA = Sooner[i].get_GPA(); }
	}

	cout << minGPA;
	return minGPA;
}

//Basic initializer
University::University() {
	//easiest to populate with cpy paste. I know I could use a loop, or use the set_Stu(), or a million other ways. Only because it's 5 items, I chose this. I wouldn't do it any farther than 10 items.
	for (int i = 0; i < 5; i++) {
		Student s;
		Sooner[i] = s;
	}
}


//......
//......
//......
// === End of Task 2 ====

int HW1_CS2413::Main()
{
	Student x[5];
	University OU;
	// ======= Test 1 =======
	// This tests your constructor function,
	// print function and header files.
	for (int i = 0; i < 5; i++) {
		x[i].prt_SID(); cout << ' ';
		x[i].prt_GPA(); cout << endl;
	}
	// === End of Test 1 ====
	// ======= Task 3 =======
	// Write a program that takes the SID
	// and GPA of five students as input
	// and assigne them to x[5].
	//
	// Formt of the inputs should be (with space)
	// SID1 GPA1 SID2 GPA2 SID3 GPA3 SID4 GPA4 SID5 GPA5
	// ......
	// ......

	for (int i = 0; i < 5; i++) {
		int sid = 0;
		float gpa = 0.0;
		cin >> sid;
		cin >> gpa;
		x[i].set_SID(sid);
		x[i].set_GPA(gpa);
	}

	// ......
	// === End of Task 3 ====
	// ======= Test 2 =======
	// This tests your set function
	for (int i = 0; i < 5; i++) {
		x[i].prt_SID(); cout << ' ';
		x[i].prt_GPA(); cout << endl;
	}
	// === End of Test 2 ====
	// ======= Test 3 =======
	// This tests your University class.
	OU.set_Stu(x);
	OU.GPA_Mean(); cout << ' ';
	OU.GPA_Max(); cout << ' ';
	OU.GPA_Min(); cout << endl;
	// === End of Test 3 ====
	// ======= Test 4 =======
	// This tests your reset function.
	for (int i = 0; i < 5; i++) {
		x[i].reset();
		x[i].prt_SID(); cout << ' ';
		x[i].prt_GPA(); cout << endl;
	}
	// === End of Test 4 ====
	return 0;
}