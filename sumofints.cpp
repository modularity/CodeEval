/* sumofints.cpp : CodeEval - Sum of Integers from File

Challenge Description

Print out the sum of integers read from a file.

Input sample:

The first argument to the program will be a text file containing a positive integer, one per line.

Output sample:

Print out the sum of all the integers read from the file. 

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int getResults(ifstream &file_in);

int main(int argc, char* argv[])
{
	ifstream file_in;
	
	file_in.open("sumofints.txt"); //argv[1]
	if(file_in.is_open() == false) {
		cout << "file open error" << endl;
		//system("pause");
		return 1;
	}

	cout << getResults(file_in) << endl;
	file_in.close();
	system("pause");
	
	return 0;
}

int getResults(ifstream &file_in) {
	int A, sum = 0;
	
	while (file_in.good()) {
		file_in >> A;	
		sum += A;
		A = 0;
	}

	return sum;
}

