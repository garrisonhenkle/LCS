/*
 * Table.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 *      Purpose:	Table is a data structure that allows for the storage of count and backtrack data.  The class also contains
 *      			methods to manipulate and update that data.
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <vector>

using namespace std;

class Table {
public:
	/**
	 * Constructor for the Table class.
	 *
	 * Takes three strings as input: the first word, the second word, and the mode
	 */
	Table(string, string, string);
	/**
	 * Deconstructor for the Table class.
	 */
	virtual ~Table();

	/**
	 * Sets the count at coordinates x,y to countVal
	 */
	void setCount(int, int, int);

	/**
	 * Gets the count at the coordinates x,y
	 */
	int getCount(int, int);

	/**
	 * Sets the direction at the coordinates x,y to DirVal
	 */
	void setDir(int, int, int);
	/**
	 * Gets the direction at the coordinates x,y
	 */
	int getDir(int, int);

	/**
	 * Populates both the count and the direction variables at x,y
	 */
	void populate(int, int, int, int);

	/**
	 * Returns the width of the table (wordOne.length)
	 */
	int getWidth();
	/**
	 * Returns the actual height of the table (2 for swap, wordTwo.length for matrix)
	 */
	int getHeight();

	/**
	 * Returns the first word
	 */
	string getOne();
	/**
	 * Returns the second word
	 */
	string getTwo();
private:
	string wOne; //the first word
	string wTwo; //the second word
	int width; //the width of a table
	int height; //the ideal height of a table
	int tableHeight; //the actual height of a table.  This value changes based on the mode of the table.
	int ** count; //contains the count data
	int ** backtrack; //contains the backtrack data
};

#endif /* TABLE_H_ */
