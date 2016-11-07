#include <iostream>
#include <string>
#include "SearchTree.h"

using namespace std;

int main() {
	SearchTree<Entry<int, string>> ds;
	Position<Entry<int, string>> p;

	try {
		cout << "size = " << ds.size() << endl;
		p = ds.find(15);
		if (!p.isExternal()) {
			cout << "Found: " << "Key=" << (*p).key() << "; Value=" << (*p).value() << endl;
		}
		else
			cout << "Not found" << endl;

		ds.insert(5, "Monday");
		ds.insert(15, "Tuesday");
		ds.insert(25, "Wednesday");
		ds.insert(11, "Thursday");
		cout << "size = " << ds.size() << endl;
		ds.printInorder();
		p = ds.find(15);
		if (!p.isExternal()) {
			cout << "Found: " << "Key=" << (*p).key() << "; Value=" << (*p).value() << endl;
		}
		ds.erase(15);
		ds.printInorder();
		ds.erase(10);
	}
	catch (std::exception &e) {
		cout << "Error: " << e.what() << endl;
	}
	//system("pause");
	return 0;
}