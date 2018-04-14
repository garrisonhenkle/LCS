/*
 * Table.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <string>;
#include <vector>;

using namespace std;

class Table {
public:
	Table(string, string, string);
	Table(int, int, string, string);
	virtual ~Table();
private:
	string wOne;
	string wTwo;
	int width;
	int height;
	pair<string, int>[][] data;
};

#endif /* TABLE_H_ */
