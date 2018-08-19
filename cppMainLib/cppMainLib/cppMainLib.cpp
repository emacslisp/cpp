//
//  cppMainLib.cpp
//  cppMainLib
//
//  Created by ewu on 19/8/18.
//  Copyright © 2018 ewu. All rights reserved.
//

#include <iostream>
#include "cppMainLib.hpp"
#include "cppMainLibPriv.hpp"

void cppMainLib::HelloWorld(const char * s)
{
    cppMainLibPriv *theObj = new cppMainLibPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void cppMainLibPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

