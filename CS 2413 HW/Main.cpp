#include <iostream>
#include "HW1_CS2413.h"
#include "HW3_CS2413.h"
#include "HW4_CS2413.h"
#include "stack.h"

using namespace std;

///*
int main() {
	int a = 1;
	//in the project, there can only be ONE main
	//a = HW1_CS2413::Main();
	//a = HW3_CS2413::Main();
	//a = HW4_CS2413::Main();
	a = stack::Main();
	return a;
}
//*/

void pointerProof() {
	int a[5] = { 0,1,2,3,4 };
	int b[6];

	int* p1 = a;
	int* p2 = &b[0];

	cout << "first elem : " << a[0] << " | " << p1[0] << *p1;

	//enumerate
	for (int i = 0; i < 5; i++) {
		cout << "pointer arr: " << p1[i] << endl;
		cout << "pointer data: " << *(p1 + i) << endl << endl;
	}

	//move to bigger list
	for (int i = 0; i < 5; i++) {
		*(p2 + i) = *(p1 + i);
	}

	//enumerate b
	for (int i = 0; i < 6; i++) {
		cout << "pointer arr: " << p2[i] << endl;
		cout << "pointer data: " << *(p2 + i) << endl << endl;
	}
}