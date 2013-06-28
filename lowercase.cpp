/*

Lowercase

Given a string write a program to convert it into lowercase.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

string getResults(ifstream &file_in);

//The first argument will be a text file containing sentences, one per line. 
int main(int argc, char* argv[]) {
	ifstream file_in;

	file_in.open(argv[1]);

	string output = getResults(file_in) + '\n';

	//Print to stdout, the lowercase version of the sentence, each on a new line.
	file_in.close();
	cout << output;

	return 0;
}

string getResults(ifstream &file_in) {
	string outputStr = "";
	string fileText;
	locale loc;

	do {
		//retreive line
		getline(file_in, fileText);

		//convert to lowercase
		for (int i = 0; i < fileText.length(); i++) {
			char current = fileText[i];
			if (current == '\n' || current == '\r') continue;
			outputStr += tolower(current, loc);
		}
		outputStr += '\n';
	} while (!file_in.eof());

	return outputStr;
}