#include <string>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
  BinarySearchTree<string, double> studentGrades;
  studentGrades.Insert("Ricardo", 2.5);
  studentGrades.Insert("Ellen", 3.5);
  studentGrades.Insert("Chen", 2.5);
  studentGrades.Insert("Kevin", 3.25);
  studentGrades.Insert("Kumar", 3.05);

  string myKey = "Ellen"; // find grade of one student
  BinarySearchTree<string, double>::Iterator it = studentGrades.Find(myKey);
  cout << "Grade of " << myKey << " is " << (*it).value_ << endl;

  studentGrades.Show(cout); // print the entire BST

  system("pause");
}
