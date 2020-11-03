#include"stdTemplateLib.h"

stdTemplateLib::stdTemplateLib() {}

void stdTemplateLib::vectors() {
	vector<string> strings(5); // Can also use just do 'strings' w/o (5) if do not want to start with any objects

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	strings[3] = "dog";
	strings[0] = "=======";
	strings[strings.size() - 1] = "=======";
	cout << strings[3] << endl;
	cout << strings.size() << endl;
	for (int i = 0; i < strings.size(); i++)
		cout << strings[i] << endl;
	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++)
		cout << *it << endl;
}

void stdTemplateLib::vectorsAndMem() {
	vector<double> numbers(20);
	int capacity = numbers.capacity();
	
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; i++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}
		numbers.push_back(i);
	}
	numbers.resize(100);
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;
	numbers.reserve(10);
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;
	numbers.clear();
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;
}
