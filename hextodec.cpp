/*
Hex to Decimal 

You will be given a hexadecimal(base 16) number. Convert it into decimal (base 10)

Input:

Your program should accept as its first argument a path to a filename. 
Each line in this file contains a hex number. 
You may assume that the hex number does not have the leading 'Ox'. 
Also all alpha characters(e.g. a through f) in the input will be in lowercase

Output:

Print out the equivalent decimal number
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int getresults(ifstream &fileIn);

int main(int argc, char* argv[]) {
	ifstream file_in;

	do {
		file_in.open(argc==2?argv[1]:"hextodec.txt");
	} while(!file_in.is_open());

	while(!file_in.eof()) {
		cout << getresults(file_in) << endl;
		system("pause");
	}

	return 0;
}

int getresults(ifstream &fileIn) {
	
	//char line[LEN+1];
	int total = 0;

	//loop through line
	//convert value to decimal
	char current;
	/*
	string lineStr;
	do {
		fileIn >> current;
		cout << current << endl;
		if(current == '\r' || current == '\n' || current == '\0') break;
		lineStr += current;
	} while(!fileIn.eof());
	*/
	string lineStr; //fileIn.getline
	fileIn >> lineStr;
	//getline(fileIn, lineStr);

	int LEN = lineStr.length();
	cout << LEN;
	for(int i = 0; i < LEN; i++) {
		
		int currInt = 0;
		//check for end of stream
		if (current == '\r' || current == '\n') break;
        //determine if char or int
		if (current >= '0' && current <= '9') {
			currInt = current - '0';
		} else 	currInt = current - 'a' + 10;
		//convert to decimal
		currInt = int(currInt * pow(16.0, (double)(LEN-1-i)));
		total += currInt;
	}
	return total;
}
 