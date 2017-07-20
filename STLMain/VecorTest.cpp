/*
 * VecorTest.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: ewu
 */

#include<iostream>
#include<vector>

using namespace std;
int main()
{
	  int myints[]={10,20,30,40,50,60,70};
	  vector<int> myvector (7);

	  copy ( myints, myints+7, myvector.begin() );

	  cout << "myvector contains:";
	  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
	    std::cout << ' ' << *it;

	  std::cout << '\n';

	  return 0;

}
