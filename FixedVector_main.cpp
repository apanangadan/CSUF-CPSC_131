#include <stdexcept>
#include <iostream>
#include <string>

#include "FixedVector.h"

using namespace std;

class Student {
private:
	string _name;
	int _nsemesters;

public:
	void print() {
		cout << "Name:" << _name << "; No. of semesters=" << _nsemesters << endl;
	}
	void setName(string name) {
		_name = name;
	}
	void setNSemesters(int n) {
		_nsemesters = n;
	}
	void updateNSemesters() {
		_nsemesters++;
	}
};

int main() {

	FixedVector<Student> students(10);

	Student s;
	for (int i = 0; i < 5; i++) {
		s.setName("Student_" + to_string(i));
		s.setNSemesters(2);
		students.set(i, s);
	}

	for (int i = 0; i < students.length(); ++i) {
		students.get(i).print();
	}
	// system("pause");
}