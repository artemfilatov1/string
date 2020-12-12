#ifndef str_hpp
#define str_hpp

#include <stdio.h>
#include <iostream>

class iterator;

class STRING{
    char* str;
    unsigned int size_s;
    bool empty;
public:
    STRING();
    STRING(char * str_);
    ~STRING();
    
    char * c_str();
    unsigned int size() const;
    void erase(const iterator& it);
    void push_back(const char& c);
    
    iterator begin();
    iterator end();
    
    void operator = (char*);
    char operator [](int idx);
};

#endif /* str_hpp */
