//
//  myString.h
//  CopyOnWritePractice
//
//  Created by Tim Lobes on 1/16/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#ifndef __CopyOnWritePractice__myString__
#define __CopyOnWritePractice__myString__

#include <stdio.h>
#include <string>

class myString {
    
private:
    struct strNode {
        std::string str;
        int instanceCount;
    };
    
    strNode* ptr;
    void detach();
    
public:
    myString() : ptr(new strNode) {ptr->instanceCount = 1; }
    myString(const std::string& setStr) : ptr(new strNode) {ptr->str = setStr; ptr->instanceCount = 1;}
    myString(const myString& other) : ptr(other.ptr) { ++ptr->instanceCount; }
    ~myString();
    myString& operator=(const myString&);
    
    char charAt(int i) const;
    void operator+=(const myString&);
};

#endif /* defined(__CopyOnWritePractice__myString__) */
