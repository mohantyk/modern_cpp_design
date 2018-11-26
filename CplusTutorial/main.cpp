//
//  main.cpp
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 11/3/16.
//  Copyright © 2016 Kaniska Mohanty. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <string>
#include <stdexcept>


using namespace std;

tuple<double, char, string> get_student(int id)
{
    if (id==0) return make_tuple(3.8, 'A', "Lisa Simpson");
    if (id==1) return make_tuple(2.9, 'C', "Ralph Wiggum");
    throw invalid_argument("id");
}

void test_for_cpp_14(void)
{
    // This function will not compile if c++14 is not supported
    int number_to_test_cpp14 = 1'000'000 ;
    if (number_to_test_cpp14 == 1000000)
    {
        std::cout << "C++ 14 supported." << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    // Test for c++14 support
    test_for_cpp_14();
    
    std::cout << "Hello, World! Welcome "<<argv[1]<<".\n";
    auto id = 0;
    auto student0 = get_student(id);
    cout    << "ID:  " << id << ", "
            << "GPA : " << get<0>(student0)<<", "
            << "grade: " << get<1>(student0)<<", "
            << "name: " << get<2>(student0)<< endl;
    
    return 0;
}
