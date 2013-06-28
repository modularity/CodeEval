/*

Multiples of a Number

Given number x and n, where n is a power of 2, print out he smallest mulitple of n which is greater than or equal to x. 
Do not use division or modulo operator.

Input: The first arg will be text file containing a comma separated list of two integers, one list per line.

Output: Print to stdout, the smallest multiple of n which is greater than or equal to x, one per line.

*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int* commaValuesToInts(ifstream &file_in);
int getResults(ifstream &file_in);

int main(int argc, char* argv[]) {

	ifstream file_in;
	string output;

	do {
		file_in.open(argc==2?argv[1]:"multiplesOfNum.txt");
	} while (!file_in.is_open());

	while(!file_in.eof()) {
		cout << getResults(file_in) << endl;
	}
	file_in.close();
	system("pause");
	return 0;
}
/* This parses each int from file
 Second number is a power of 2
 returns the smallest multiple of n which is greater than or equal to x
 doesn't reference modulus or division
 loops over 2 until num is greater than or equal to x
*/
int getResults(ifstream &file_in) {
	int result = 2;
	//parse by comma delimitter
	int* data = commaValuesToInts(file_in);
	result = data[1];
	//cout << data[0] << " " << result; system("pause");
	while (result < data[0]) {
		result*=2;
	}
	return result;
}
int* commaValuesToInts(ifstream &file_in) {
	int* result = new int[2];
	char del;
	file_in >> result[0];
	file_in >> del;
	file_in >> result[1];
	return result;
}