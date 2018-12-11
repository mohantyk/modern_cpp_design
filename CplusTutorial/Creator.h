//
//  Creator.h
//  CplusTutorial
//
//  Created by Kaniska Mohanty on 12/11/18.
//  Copyright © 2018 Kaniska Mohanty. All rights reserved.
//

#ifndef Creator_h
#define Creator_h

#include <cstdlib>

template <class T>
struct OpNewCreator
{
    static T* Create()
    {
        return new T;
    }
};


template <class T>
struct MallocCreator
{
    static T* Create()
    {
        auto buf = std::malloc(sizeof(T));
        if(!buf){ return nullptr; }
        return new(buf) T;
    }
};

template <class T>
struct PrototypeCreator
{
    PrototypeCreator(T* pObj = nullptr)
    :pPrototype_(pObj)
    { }
    
    T* Create() // does not have to be static since we need to initialize with a prototype anyway
    {
        return pPrototype_ ? pPrototype_->Clone() : nullptr ;
    }
    T* GetPrototype(){ return pPrototype_; }
    void SetPrototype(T* pObj){ pPrototype_ = pObj; }
    
private:
    T* pPrototype_;
};

// Examples
void creator_example(void);

/*
 // Example of a class using such a Creator Policy
 template <class CreationPolicy>
 class WidgetManager: public CreationPolicy
 { ... };
 
 //Application Code
 typedef WidgetManager< MallocCreator<Widget> > MyWidgetMgr;
 
*/

/*
 // Another example
 template <template <class Created> class CreationPolicy>
 class WidgetManager: public CreationPolicy<Widget>
 {...};
 
 //Applicatin Code
 typedef WidgetManager < MallocCreator > MyWidgetMgr;
*/


#endif /* Creator_h */
