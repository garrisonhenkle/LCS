/*
 * Table.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 */

#include "Table.h"
#include <vector>;

Table::Table(string wordOne, string wordTwo, string mode) {

	wOne = " " + wordOne;
	wTwo = " " + wordTwo;
	width = wOne.length();
	height = wTwo.length();

	//set the height of the 2D arrays to either the matrix or swap sizes
	if (mode == "swap") {
		tableHeight = 2;
	} else {
		tableHeight = height;
	}

	//set the two 2D arrays to the correct dimensions
	count = new int[width][tableHeight];
	backtrack = new int[width][tableHeight];

	//initialize the tables to zeros
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < tableHeight; j++) {
			count[i][j] = 0;
			backtrack[i][j] = 0;
		}
	}
}

Table::~Table() {
	delete backtrack;
	delete count;
}

void Table::setCount(int x, int y, int countVal) {

	//set the count at the coordinates (x,y) to countVal
	count[x][y] = countVal;
}

int Table::getCount(int x, int y) {

	//return the value of the countVal at coordinates (x,y)
	return count[x][y];
}

void Table::setDir(int x, int y, int dirVal) {

	//set the count at the coordinates (x,y) to countVal
	backtrack[x][y] = dirVal;
}

int Table::getDir(int x, int y) {

	//return the value of the dirVal at coordinates (x,y)
	return backtrack[x][y];
}

void Table::populate(int x, int y, int countVal, int dirVal) {

	//set the count and direction at the coordinates (x,y) to countVal and dirVal, respectively
	count[x][y] = countVal;
	backtrack[x][y] = dirVal;

}

int Table::getWidth(){
	return width;
}

int Table::getHeight(){
	return height;
}

string Table::getOne(){
	return wOne;
}

string Table::getTwo(){
	return wTwo;
}
