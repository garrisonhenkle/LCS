/*
 * LCS.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 *
 */

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
#include "LCS.h"

//gets the input from the command line and runs the program
int main(int argc, char* argv[]) {

	//holds the two sequences to be compared
	string one;
	string two;

	//if there is two command line arguments, assign them to be the strings
	if (argc == 3) {
		one = argv[1];
		two = argv[2];
		//if argc != 3, then give an error and exit
	} else {
		cerr << "Invalid amount of arguments.  Please see the readme.txt"
				<< endl;
		return 1;
	}

	//create the matrix and the swap table
	Table * matrix = new Table(one, two, "matrix");
	Table * swap = new Table(one, two, "swap");

	//create the LCS object
	LCS * lcs = new LCS();

	//
	//get the longest common subsequence
	//uses the matrix
	//

	//populate the matrix
	lcs->populateMatrix(matrix, matrix->getOne(), matrix->getTwo());
	//print the longest common subsequence
	cout << lcs->getLCS(matrix, matrix->getOne()) << endl;

	//
	//get the length of the longest common subsequence
	//uses the swap table
	//

	//populate the swap
	lcs->populateSwap(swap, swap->getOne(), swap->getTwo());
	//print the length of the longest common subsequence
	cout << lcs->getLCSLength(swap) << endl;

	//delete the matrix, the swap table, and the LCS object
	delete matrix;
	delete swap;
	delete lcs;

	return 0;
} //end main

//see header file
void LCS::populateMatrix(Table * t, string wordOne, string wordTwo) {

	//holds the current characters being compared
	char currXChar; //horizontal / x axis
	char currYChar; //vertical / y axis

	int countVal;

	for (int j = 1; j < t->getHeight(); j++) {

		for (int i = 1; i < t->getWidth(); i++) {

			//set the current characters that are being compared

			currXChar = wordOne[i];
			currYChar = wordTwo[j];

			//if the characters are the same, set the count to the diagonal + 1
			//and the direction to diagonal
			if (currXChar == currYChar) {

				//get the count of the diagonal and add one
				countVal = t->getCount(i - 1, j - 1) + 1;

				//set the count of the current cell
				t->setCount(i, j, countVal);

				//set the direction of the current cell to diagonal
				t->setDir(i, j, 2);

				//if the count of the cell above the current cell is greater than
				//that of the cell to its left, set count to that of the above cell
				//and set the direction to up
			} else if (t->getCount(i, j - 1) >= t->getCount(i - 1, j)) {

				//get the count of the up cell
				countVal = t->getCount(i, j - 1);

				//set the count of the current cell
				t->setCount(i, j, countVal);

				//set the direction of the current cell to up
				t->setDir(i, j, 3);

				//else set the count to that of the cell to the left and set the direction to left
			} else {

				//get the count of the left cell
				countVal = t->getCount(i - 1, j);

				//set the count of the current cell
				t->setCount(i, j, countVal);

				//set the direction of the current cell to left
				t->setDir(i, j, 1);
			}

		} //end for horizontal
	} //end for vertical

} //end populateMatrix

//see header file
string LCS::getLCS(Table * t, string wordOne) {

	string out = "";

	//current pointer position
	int xLoc = t->getWidth() - 1;
	int yLoc = t->getHeight() - 1;

	//get the longest common subsequence from the matrix
	while (t->getCount(xLoc, yLoc) != 0) {

		//get the direction of the current cell
		int dirVal = t->getDir(xLoc, yLoc);

		//if the direction is diagonal
		if (dirVal == 2) {

			//push the letter to the front
			out = wordOne[xLoc] + out;

			//adjust the position variables
			xLoc--;
			yLoc--;

			//if the direction is up
		} else if (dirVal == 3) {

			//adjust the position variables
			yLoc--;

			//if the direction is left
		} else if (dirVal == 1) {

			//adjust the position variables
			xLoc--;
		}

	} //end while

	return out;
} //end getLCS

//see header file
void LCS::populateSwap(Table * t, string wordOne, string wordTwo) {

	LCS * lcs2 = new LCS();

	int swapHeight = wordTwo.length();

	for (int j = 0; j < swapHeight; j++) {

		//move the bottom row to the top (store row 1 in row 0)
		for (int i = 0; i < t->getWidth(); i++) {
			t->setCount(i, 0, t->getCount(i, 1));
		}

		//write the new line over the data in row 1
		populateLine(t, wordOne, wordTwo, 1, j); //maybe j + 1 **********************
	}

	delete lcs2;

} //end populateSwap

//see header file
int LCS::getLCSLength(Table * t) {

	return t->getCount(t->getWidth() - 1, t->getHeight() - 1);
} // end getLCSLength

//see header file
void LCS::populateLine(Table * t, string wordOne, string wordTwo, int tableLine,
		int wordLine) {

	//holds the current characters being compared
	char currXChar; //horizontal / x axis
	char currYChar; //vertical / y axis

	int countVal;

	//go through every character on the line
	for (int i = 1; i < t->getWidth(); i++) {

		currXChar = wordOne[i];
		currYChar = wordTwo[wordLine]; //check this later ****************************************************

		//if the characters are the same, set the count to the diagonal + 1
		//and the direction to diagonal
		if (currXChar == currYChar) {

			//get the count of the diagonal and add one
			countVal = t->getCount(i - 1, tableLine - 1) + 1;

			//set the count of the current cell
			t->setCount(i, tableLine, countVal);

			//set the direction of the current cell to diagonal
			t->setDir(i, tableLine, 2);

			//if the count of the cell above the current cell is greater than
			//that of the cell to its left, set count to that of the above cell
			//and set the direction to up
		} else if (t->getCount(i, tableLine - 1)
				>= t->getCount(i - 1, tableLine)) {

			//get the count of the up cell
			countVal = t->getCount(i, tableLine - 1);

			//set the count of the current cell
			t->setCount(i, tableLine, countVal);

			//set the direction of the current cell to up
			t->setDir(i, tableLine, 3);

			//else set the count to that of the cell to the left and set the direction to left
		} else {

			//get the count of the left cell
			countVal = t->getCount(i - 1, tableLine);

			//set the count of the current cell
			t->setCount(i, tableLine, countVal);

			//set the direction of the current cell to left
			t->setDir(i, tableLine, 1);
		}
	}

} //end populateLine

//
