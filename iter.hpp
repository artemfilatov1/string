#ifndef iter_hpp
#define iter_hpp

#include <stdio.h>
#include "str.hpp"

class iterator{
    int idx;
    STRING * str;
    iterator() = delete;
public:
    iterator(STRING * s, int idx = 0);
    iterator(const iterator& it);
    
    char operator *();
    iterator operator++();
    iterator operator--();
    iterator operator++(int);
    iterator operator--(int);
    void operator=(const iterator& it);
    bool operator==(const iterator& it);
    bool operator!=(const iterator& it);
    
    friend class STRING;
};

#endif /* iter_hpp */
