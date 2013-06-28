/*

Sum of Digits

Given a positive integer, find the sum of its constiuent digits

Input: The first argument will be a text file containing postive integers, one per line.

Output: Print to stdout, the sum of the numbers that make up the integer, one per line.

*/
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

int getresult(ifstream &file_in);

int main(int argc, char* argv[]) {
	ifstream file_in;

	do {
		file_in.open(argc > 1?argv[1]:"sumofdigits.txt");
		//file_in.open(argv[1]);
	} while(!file_in.is_open());

	//check file for postive value and return result
	while (!file_in.eof()) {
		cout << getresult(file_in) << endl;
	}
	system("pause");
	return 0;
}


/*input as a c-string 
	then parse each digit in collection, cast to int and add to result
	then return final result
*/
int getresult(ifstream &file_in) {
	int result = 0;
	char input[20];

	//parse as cstring
	file_in.getline(input, 20);

	//parse per digit, cast to int and add to result
	for (int i = 0; i < strlen(input); i++) {
		char current = input[i];
		if (current == '\n' || current == '\r') break;
		result += current - '0';
	}
	return result;
}