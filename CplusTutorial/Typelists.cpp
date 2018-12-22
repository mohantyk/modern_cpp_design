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
    std::cout << std::endl;
}

void check_typelist_indexing(void)
{
    typedef TypeAt<SignedIntegrals, 2>::Result IndexedType;
    std::cout << "Indexed type comparison with int (should be 1): " << (typeid(IndexedType)==typeid(int)) << std::endl;
    std::cout << "Indexed type comparison with long int (should be 0): " << (typeid(IndexedType)==typeid(long int)) << std::endl;
    std::cout << std::endl;
    
}

void check_typelist_search(void)
{
    int searchResultForInt(IndexOf<SignedIntegrals, int>::value);
    int searchResultForUnsignedChar(IndexOf<SignedIntegrals, unsigned char>::value);
    cout << "Index of type int in SignedIntegrals (should be 2): " << searchResultForInt << endl;
    cout << "Index of type unsigned char in SignedIntegrals (should be -1): " << searchResultForUnsignedChar << endl;
    cout << endl;
}

void check_typelist_append(void)
{
    std::vector<char> myVector(Length< Append<SignedIntegrals, AllCharTypes>::Result >::value);
    cout << "Length of appended typelist (should be 7): " << myVector.size() << endl;
    cout << endl;
}

void check_typelist_erase(void)
{
    typedef Erase<SignedIntegrals, short int>::Result ErasedTypelist;
    int IndexOfLongIntBeforeErase(IndexOf<SignedIntegrals, long int>::value);
    int IndexOfLongIntAfterErase(IndexOf<ErasedTypelist, long int>::value);
    cout << "Index of type long int in original typelist (should be 3): " << IndexOfLongIntBeforeErase << endl;
    cout << "Index of type long int in erased typelist (should be 2): " << IndexOfLongIntAfterErase << endl;
    cout << endl;
}

void check_typelist_eraseall(void)
{
    typedef TYPELIST_5(signed char, short int, int, short int, long int) SignedIntegralsRepeated;
    typedef Erase<SignedIntegrals, short int>::Result EraseAllTypelist;
    int IndexOfLongIntBeforeErase(IndexOf<SignedIntegralsRepeated, long int>::value);
    int IndexOfLongIntAfterErase(IndexOf<EraseAllTypelist, long int>::value);
    cout << "Index of type long int in original typelist (should be 4): " << IndexOfLongIntBeforeErase << endl;
    cout << "Index of type long int in erased typelist (should be 2): " << IndexOfLongIntAfterErase << endl;
    cout << endl;
}


void typelist_checks(void)
{
    cout << "TYPELIST CHECKS" << endl;
    check_typelist_length();
    check_typelist_indexing();
    check_typelist_search();
    check_typelist_append();
    check_typelist_erase();
    check_typelist_eraseall();
    cout << endl;
}














