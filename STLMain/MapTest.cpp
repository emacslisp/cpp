/*
 * MapTest.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: ewu
 */

#include "MapTest.h"
#include <map>
#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

MapTest::MapTest() {
	// TODO Auto-generated constructor stub

}

MapTest::~MapTest() {
	// TODO Auto-generated destructor stub
}

void MapTest:: MapExampe() {

	 map<int, string> Employees;

	 // 1) Assignment using array index notation

	 Employees[5234] = "Mike C.";

	 Employees[3374] = "Charlie M.";

	 Employees[1923] = "David D.";

	 Employees[7582] = "John A.";

	 Employees[5328] = "Peter Q.";



	 cout << "Employees[3374]=" << Employees[3374] << endl << endl;



	 cout << "Map size: " << Employees.size() << endl;



	 cout << endl << "Natural Order:" << endl;

	 for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)

	 {

	     cout << (*ii).first << ": " << (*ii).second << endl;

	 }



	 cout << endl << "Reverse Order:" << endl;

	 for( map<int,string>::reverse_iterator ii=Employees.rbegin(); ii!=Employees.rend(); ++ii)

	 {

	     cout << (*ii).first << ": " << (*ii).second << endl;

	   }

}
