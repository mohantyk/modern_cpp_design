//
//  Typelists.hpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/12/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#ifndef Typelists_hpp
#define Typelists_hpp

#include <stdio.h>

template <typename T, typename U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

class NullType {};

#define TYPELIST_1(T1)              Typelist<T1, NullType>
#define TYPELIST_2(T1, T2)          Typelist<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3)      Typelist<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4)  Typelist<T1, TYPELIST_3(T2, T3, T4) >

// Length of a Typelist
template <typename TList> struct Length;
template <> struct Length<NullType>
{
    enum {value = 0};
};
template <typename T, typename U>
struct Length<Typelist<T, U> >
{
    enum { value = 1 + Length<U>::value };
};
void check_typelist_length(void); // For testing

//Indexed access to a Typelist
//template <typename TList, unsigned int i>


void typelist_checks(void);
#endif /* Typelists_hpp */
