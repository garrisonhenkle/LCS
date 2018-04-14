/*
 * Table.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 */


#include "Table.h"

Table::Table(string wordOne, string wordTwo, string mode) {
	wOne = " " + wordOne;
	wTwo = " " + wordTwo;
	width = wOne.length();
	height = wTwo.length();
	data = vector<vector<pair<int, string>>>;

}

Table::Table(int height, int width,)

Table::~Table() {

}

