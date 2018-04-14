/*
 * LCD.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 */

#include "LCD.h"

int main(int argc, char* argv[]) {

	//holds the two sequences to be compared
	string one;
	string two;

	//holds the current characters being compared
	char currXChar; //horizontal / x axis
	char currYChar; //vertical / y axis

	//holds the longest common subsequence
	string LCSeq;

	//holds the length of the longest common subsequence
	int LCSeqLength;

	//holds the count of a cell
	int countVal;

	//if there is two command line arguments, assign them to be the strings
	if (argc == 2) {
		one = argv[0];
		two = argv[1];
		//if argc != 2, then give an error and exit
	} else {
		cerr << "Invalid amount of arguments.  Please see the readme.txt"
				<< endl;
		return 1;
	}

	//create the matrix and the swap table
	Table * matrix = new Table(one, two, "matrix");
	Table * swap = new Table(one, two, "swap");

	//
	//Get the longest common subsequence using the matrix
	//

	//Note about the direction matrix:
	//The direction is given by a value from 1-3
	//1 is left, 2 is the upper left diagonal, and 3 is up
	//-------------
	//|  2  |  3  |
	//|-----------|
	//|  1  |  c  |
	//-------------
	//
	// c is the current cell

	for (int j = 1; j < matrix->getHeight(); j++) {

		for (int i = 1; i < matrix->getWidth(); i++) {

			//set the current characters that are being compared

			//since the for loops start at 1 to account for the extra space
			//character added to the front of each word, the currChar variables
			//must be set to the i-1 or j-1 character of the word
			currXChar = one[i - 1];
			currYChar = two[j - 1];

			//if the characters are the same, set the count to the diagonal + 1
			//and the direction to diagonal
			if (currXChar == currYChar) {

				//get the count of the diagonal and add one
				countVal = matrix->getCount(i - 1, j - 1) + 1;

				//set the count of the current cell
				matrix->setCount(i, j, countVal);

				//set the direction of the current cell to diagonal
				matrix->setDir(i, j, 2);

				//if the count of the cell above the current cell is greater than
				//that of the cell to its left, set count to that of the above cell
				//and set the direction to up
			} else if (matrix->getCount(i, j - 1)
					>= matrix->getCount(i - 1, j)) {

				//get the count of the up cell
				countVal = matrix->getCount(i, j - 1);

				//set the count of the current cell
				matrix->setCount(i, j, countVal);

				//set the direction of the current cell to up
				matrix->setDir(i, j, 3);

				//else set the count to that of the cell to the left and set the direction to left
			} else {

				//get the count of the left cell
				countVal = matrix->getCount(i - 1, j);

				//set the count of the current cell
				matrix->setCount(i, j, countVal);

				//set the direction of the current cell to left
				matrix->setDir(i, j, 1);
			}

		}
	}

	//
	//Get the length of the longest common subsequence using the swap table
	//

	//delete the matrix and the swap table
	delete matrix;
	delete swap;

	return 0;
} //end main
