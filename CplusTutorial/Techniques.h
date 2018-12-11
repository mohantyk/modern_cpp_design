//
//  Techniques.h
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/11/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#ifndef Techniques_h
#define Techniques_h

#include <cassert>

#define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0]; }


class Interface
{
public:
    virtual void Fun() = 0;
};

// Adapter pattern using a local class
template <typename T, typename P>
Interface* MakeAdapter(const T& obj, const P& arg)
{
    class Local: public Interface
    {
    public:
        Local(const T& obj, const P& arg)
        : obj_(obj), arg_(arg) {}
        
        virtual void Fun()
        {
            obj_.Call(arg_);
        }
    private:
        T obj_;
        P arg_;
    };
    return new Local(obj, arg);
}

#endif /* Techniques_h */
