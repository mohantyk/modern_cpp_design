//
//  main.cpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 11/3/16.
//  Copyright © 2016 Kaniska Mohanty. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <memory>

#include "Creator.h"

#define MAGIC_CONSTANT 42

using namespace std;


int main(int argc, const char * argv[]) {
    OpNewCreator<int> tempStruct;
    std::unique_ptr<int> temp_ptr(tempStruct.Create());
    
    *temp_ptr = MAGIC_CONSTANT;
    
    cout << *temp_ptr << endl;
    
    return 0;
}
