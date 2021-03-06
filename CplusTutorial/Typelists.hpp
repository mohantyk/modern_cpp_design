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
#include <iostream>
#include <typeinfo>

template <typename T, typename U>
struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

class NullType {};

#define TYPELIST_1(T1)                      Typelist<T1, NullType>
#define TYPELIST_2(T1, T2)                  Typelist<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3)              Typelist<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4)          Typelist<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5)      Typelist<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6)  Typelist<T1, TYPELIST_5(T2, T3, T4, T5, T6) >

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
template <typename TList, unsigned int i> struct TypeAt;

template <typename Head, typename Tail>
struct TypeAt<Typelist<Head, Tail>, 0>
{
    typedef Head Result;
};

template <typename Head, typename Tail, unsigned int i>
struct TypeAt<Typelist<Head, Tail>, i>
{
    typedef typename TypeAt<Tail, i-1>::Result Result;
};

void check_typelist_indexing(void); // For testing


// Search a Typelist
template <typename TList, typename T> struct IndexOf;

template <typename T>
struct IndexOf<NullType, T>
{
    enum { value = -1 };
};

template <typename Tail, typename T>
struct IndexOf<Typelist<T, Tail>, T>
{
    enum { value = 0 };
};

template <typename Head, typename Tail, typename T>
struct IndexOf<Typelist<Head, Tail>, T>
{
private:
    enum { temp = IndexOf<Tail, T>::value } ;
public:
    enum { value = temp == -1 ? -1 : 1 + temp} ;
    
};

void check_typelist_search(void);

// Append to a Typelist
template <typename TList, typename T> struct Append;

template <>
struct Append<NullType, NullType>
{
    typedef NullType Result;
};

template <typename T>
struct Append<NullType, T>
{
    typedef Typelist<T, NullType> Result;
};

template <typename Head, typename Tail>
struct Append<NullType, Typelist<Head, Tail> >
{
    typedef Typelist<Head, Tail> Result;
};

template <typename Head, typename Tail, typename T>
struct Append<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head,
                    typename Append<Tail, T>::Result>
            Result;
};

void check_typelist_append(void);

// Erase Type from a Typelist (only first occurence removed)
template <typename TList, typename T> struct Erase;

template <typename T>
struct Erase<NullType, T>
{
    typedef NullType Result;
};

template <typename Head, typename Tail>
struct Erase<Typelist<Head, Tail>, Head>
{
    typedef Tail Result;
};

template <typename Head, typename Tail, typename T>
struct Erase<Typelist<Head, Tail>, T>
{
    typedef Typelist<Head,
                    typename Erase<Tail, T>::Result >
        Result;
};

void check_typelist_erase(void);

// Erase all occurences of Type from Typelist
template <typename TList, typename T> struct EraseAll;

template <typename T>
struct EraseAll<NullType, T>
{
    typedef NullType Result;
};

template <typename Head, typename Tail>
struct EraseAll<Typelist<Head, Tail>, Head>
{
    typedef EraseAll<Tail, Head> Result;
};

template <typename Head, typename Tail, typename T>
struct EraseAll<Typelist<Head, Tail>, T>
{
    typedef EraseAll<Head,
                    typename EraseAll<Tail, T>::Result >
                Result;
};
void check_typelist_eraseall(void);


// Remove duplicates from a typelist
template <typename TList> struct NoDuplicates;

template <>
struct NoDuplicates<NullType>
{
    typedef NullType Result;
};

template <typename Head, typename Tail>
struct NoDuplicates<Typelist<Head, Tail> >
{
    typedef typename NoDuplicates<Tail>::Result L1;
    typedef typename Erase<L1, Head>::Result NewTail;
    typedef Typelist<Head, NewTail> Result;
};
void check_typelist_noduplicates(void);


// Replacing an element
template <typename TList, typename Original, typename Replacement> struct Replace;

template<typename Original, typename Replacement>
struct Replace<NullType, Original, Replacement>
{
    typedef NullType Result;
};

template <typename Tail, typename Original, typename Replacement>
struct Replace<Typelist<Original, Tail>, Original, Replacement>
{
    typedef Typelist<Replacement, Tail> Result;
};

template <typename Head, typename Tail, typename Original, typename Replacement>
struct Replace<Typelist<Head, Tail>, Original, Replacement>
{
    typedef Typelist<Head,
                        typename Replace<Tail, Original, Replacement>::Result >
                Result;
};
void check_typelist_replace(void);



// Wrappers
void typelist_checks(void); // For testing all typelist functionality
#endif /* Typelists_hpp */









