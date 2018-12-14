//
//  Creator.cpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/11/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <memory>
#include "Creator.h"

#define MAGIC_CONSTANT 42

void creator_example(void)
{
    OpNewCreator<int> tempStruct;
    std::unique_ptr<int> temp_ptr(tempStruct.Create());
    *temp_ptr = MAGIC_CONSTANT;
    std::cout << "Creator example of an int ptr (should be 42): " << *temp_ptr << std::endl;
    std::cout << std::endl;
}
