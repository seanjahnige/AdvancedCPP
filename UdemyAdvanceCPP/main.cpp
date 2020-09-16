#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void readFiles();
void writeFiles();
void parseTextFiles();
void structAndPadding();
void readWriteBinaryFiles();


int main() {
	//writeFiles();
	//readFiles();
	//parseTextFiles();
	//structAndPadding();
	readWriteBinaryFiles();

	system("pause");
	return 0;
}

void writeFiles() {
	ofstream outFile;
	fstream outFile2;
	string outputFileName = "text.txt", outputFileName2 = "text2.txt";

	outFile.open(outputFileName, ios::out);
	outFile2.open(outputFileName2);
	if (outFile.is_open()) {
		outFile << "Hello there" << endl;
		outFile << 123;
		outFile.close();
	}
	else {
		cout << "Could not open file" << endl;
	}
}

void readFiles() {
	//cout << "Write" << endl;
	ifstream inFile;
	fstream inFile2;
	string inFileName = "text.txt";

	inFile.open(inFileName);
	inFile2.open(inFileName, ios::in);
	if (inFile.is_open()) {
		string line;

		while (!inFile.eof()) { // not end of file
			getline(inFile, line);
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cout << "Cannot open file: " << inFileName << endl;
	}
}

void parseTextFiles(){
	string filename = "stats.txt";
	ifstream input;

	input.open(filename);
	if (!input.is_open()) {
		return;
	}
	while (input) {
		string line;

		getline(input, line, ':');

		int population;
		input >> population;

		//input.get();
		input >> ws; // For both of these commands, the invisible new line character is taken out 

		if (!input) {
			break;
		}

		cout << line << " -- " << population << endl;
	}
	input.close();

	return;
}

void structAndPadding() {
#pragma pack(push, 1) // See the result but only pushes the required bytes 64 instead of 64 in this case, 1 means every byte should be "checked"
	struct Person {
		char name0[50];
		int age0;
		double weight0;
	};
#pragma pack(pop) // Stops the #pragma pack(push, 1)
	struct PersonUnPacked {
		char name1[50];
		int age1;
		double weight1;
	};

	cout << sizeof(Person) << endl; //Gets how many bytes Person has - int:4 double:8 name:50
	cout << sizeof(PersonUnPacked) << endl;
}

void readWriteBinaryFiles() {
#pragma pack(push, 1)
	struct Person2 {
		char name2[50];
		int age2;
		double weight2;
	};
#pragma pack(pop)

	///// WRITE BINARY FILE /////

	Person2 someone = { "Frodo", 220, 0.8 };

	string fileName = "BinaryTest.bin";
	ofstream outputFile;
	outputFile.open(fileName, ios::binary);
	if (outputFile.is_open()) {
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person2));
		outputFile.close();
	}
	else {
		std::cout << "Could not creat file " + fileName << std::endl;
	}

	///// READ BINARY FILE /////

	Person2 someoneElse = {};
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);
	if (inputFile.is_open()) {
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person2));
		inputFile.close();
	}
	else {
		std::cout << "Could not creat file " + fileName << std::endl;
	}

	std::cout << someoneElse.name2 << ", " << someoneElse.age2 << ", " << someoneElse.weight2 << std::endl;
}
