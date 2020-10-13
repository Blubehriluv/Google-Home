#include <string>
#include <iostream>
#include <fstream>



void WriteLineToFile(std::string lineOfText);
void ReadLineFromFile(std::string searchWord);
void GetInfo();

int main() {

	std::cout << "Hello there" << std::endl;
	WriteLineToFile("This text should appear");
	GetInfo();

	system("Pause");
	return 0;
}

void WriteLineToFile(std::string lineOfText) {
	std::ofstream myFile;

	//Use the append to keep the current data.
	myFile.open("page.txt", std::ios_base::app);
	myFile << lineOfText;

	myFile.close();
}

void ReadLineFromFile(std::string searchWord) {

	std::ifstream fileInput;
	int offset;
	string line;
	char* search = "a";

	unsigned int curLine = 0;
	while (getline(fileInput, line)) { // I changed this, see below
		curLine++;
		if (line.find(search, 0) != string::npos) {
			cout << "found: " << search << "line: " << curLine << endl;
		}
	}
}

void GetInfo() {
	std::string fileData;
	for (int i = 0; i <= 2; i++) {
		std::cout << "enter data" << std::endl;
		getline(std::cin, fileData);
		WriteLineToFile("\n");
		WriteLineToFile(fileData);

	}
}