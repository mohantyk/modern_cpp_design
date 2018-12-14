//
//  Typelists.cpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/12/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#include <vector>
#include <iostream>
#include <typeinfo>

#include "Typelists.hpp"

using namespace std;

typedef Typelist<int, NullType> OneTypeOnly;
typedef Typelist<char, Typelist<signed char, Typelist<unsigned char, NullType> > > AllCharTypes;
typedef TYPELIST_4(signed char, short int, int, long int) SignedIntegrals;

void check_typelist_length(void)
{
    std::vector<int> myVector(Length<SignedIntegrals>::value);
    std::cout << "Length of typelist(should be 4): " << myVector.size() << std::endl;
}

void check_typelist_indexing(void)
{
    typedef TypeAt<SignedIntegrals, 2>::Result IndexedType;
    std::cout << "Indexed type comparison with int (should be 1): " << (typeid(IndexedType)==typeid(int)) << std::endl;
    std::cout << "Indexed type comparison with long int (should be 0): " << (typeid(IndexedType)==typeid(long int)) << std::endl;
    
}

void check_typelist_search(void)
{
    int searchResult(IndexOf<SignedIntegrals, int>::value);
    cout << "Index of type int in SignedIntegrals (should be 2): " << searchResult << endl;
}

void typelist_checks(void)
{
    check_typelist_length();
    check_typelist_indexing();
    check_typelist_search();
}
