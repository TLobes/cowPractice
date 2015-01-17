//
//  myString.cpp
//  CopyOnWritePractice
//
//  Created by Tim Lobes on 1/16/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include "myString.h"
#include <string>

myString::~myString() {
    --ptr->instanceCount;
    if (ptr->instanceCount == 0)
        delete ptr;
}

myString& myString::operator=(const myString& other)
{
    if (this == &other || ptr == other.ptr)
        return *this;
    
    --ptr->instanceCount;
    
    if (ptr->instanceCount == 0)
        delete ptr;
    
    ptr = other.ptr;
    ++ptr->instanceCount;
    return *this;
}

void myString::detach()
{
    if(ptr->instanceCount == 1)
        return;

    strNode* temp = new strNode;
    temp->str = ptr->str;
    temp->instanceCount = 1;
    --ptr->instanceCount;
    ptr = temp;
}

char myString::charAt(int i) const
{
    return ptr->str[i];
}

void myString::operator+=(const myString& other)
{
    detach();
}
