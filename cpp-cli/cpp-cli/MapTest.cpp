//
//  MapTest.cpp
//  cpp-cli
//
//  Created by ewu on 23/2/20.
//  Copyright © 2020 ewu. All rights reserved.
//

#include "MapTest.hpp"

void MapTest::main() {
    map<string,int> ages;
    
    ages["Mike"] = 40;
    ages["John"] = 50;
    ages["Vicky"] = 20;
    
    cout << ages["Mike"] << endl;
    
    ages.insert(pair<string, int> ("Peter", 100));
    
    for(map<string, int>::iterator it = ages.begin(); it!=ages.end();it++) {
        cout << it->first << ": " << it->second<<endl;
    }
    
    cout << "============" <<endl;
    
    for(map<string, int>::iterator it = ages.begin(); it!=ages.end();it++) {
        pair<string, int> age = *it;
        cout << age.first << ": " << age.second<<endl;
    }
    
    cout << "============" <<endl;
}
