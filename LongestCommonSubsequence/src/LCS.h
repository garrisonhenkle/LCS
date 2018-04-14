/*
 * LCS.h
 *
 *  Created on: Apr 12, 2018
 *      Author: Garrison Henkle
 */

#ifndef LCS_H_
#define LCS_H_

#include "Table.h";
#include <iostream>;

class LCS {
public:
	void populateMatrix(Table&);
	string getLCS(Table&);
};

#endif /* LCS_H_ */
