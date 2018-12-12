//
//  Typelists.cpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/12/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#include <vector>
#include <iostream>

#include "Typelists.hpp"

typedef Typelist<int, NullType> OneTypeOnly;
typedef Typelist<char, Typelist<signed char, Typelist<unsigned char, NullType> > > AllCharTypes;
typedef TYPELIST_4(signed char, short int, int, long int) SignedIntegrals;

void check_typelist_length(void)
{
    std::vector<int> myVector(Length<SignedIntegrals>::value);
    std::cout << "Length of typelist(should be 4): " << myVector.size() << std::endl;
}

void typelist_checks(void)
{
    check_typelist_length();
}
