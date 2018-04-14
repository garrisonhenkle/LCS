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
	virtual ~Table();

	void setCount(int, int, int);
	int getCount(int, int);

	void setDir(int, int, int);
	int getDir(int, int);

	void populate(int, int, int, int);

	int getWidth();
	int getHeight();
private:
	string wOne;
	string wTwo;
	int width;
	int height;
	int tableHeight;
	int * count[][];
	int * backtrack[][];
};

#endif /* TABLE_H_ */
