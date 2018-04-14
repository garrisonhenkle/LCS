/*
 * LCS.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 *      Purpose: 	Contains methods that find and display the longest common subsequence.
 *      			The longest common subsequence (LCS) is found through either the swap method
 *      			or the matrix method.  The matrix method produces both LCS and its length, while
 *      			the swap method produces just the length with linear space.
 */

#ifndef LCS_H_
#define LCS_H_

#include "Table.h"
#include <iostream>

class LCS {
public:

	/**
	 * Populates the input table in matrix mode with data.
	 *
	 * Both backtracking and count data is found using the strings wordOne and wordTwo.
	 *
	 * This method uses n^2 space and allows for both the LCS and its length to be found.
	 *
	 */
	void populateMatrix(Table*, string, string);

	/**
	 * Finds the LCS of an input table and returns it as a string.
	 *
	 * The required input is a table in matrix mode in the table parameter and either wordOne or wordTwo in the string parameter
	 */
	string getLCS(Table*, string);

	/**
	 * Populates the input table in swap mode with data.
	 *
	 * Only the count data can be derived using the strings wordOne and wordTwo.
	 *
	 * This method uses linear space and allows for only the length of the LCS to be found.
	 *
	 * This method uses two rows of the matrix and swaps the bottom row to the top to calculate the matrix in linear space.
	 * The result is the bottom two rows of the output of populateMatrix.
	 */
	void populateSwap(Table*, string, string);
	/**
	 * Returns the length of the LCS from the input table.
	 *
	 * The input table can be in either swap or matrix mode
	 */
	int getLCSLength(Table*);

	/**
	 * Populates a single row of an input matrix.
	 *
	 * The required input is a table (in either swap or matrix mode), strings wordOne and wordTwo, the row to populate,
	 * and the index of the current character of wordTwo
	 */
	void populateLine(Table*, string, string, int, int);
};

#endif /* LCS_H_ */
