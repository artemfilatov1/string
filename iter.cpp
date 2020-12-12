#include "iter.hpp"

#define END -1

iterator::iterator(STRING * s, int idx): str(s), idx(idx){}

iterator::iterator(const iterator& it){
    operator=(it);
}

char iterator::operator *(){
    if (idx == END) return '\0';//or 0
    return (*str)[idx];
}

iterator iterator::operator++(){
    int old_idx = idx;
    if (idx == END) return (*this);
    idx++;
    if (idx == str->size()) idx = END;
    return iterator(str, old_idx);
}

iterator iterator::operator--(){
    int old_idx = idx;
    if (idx == END)
        idx = (int)str->size()-1;
    
    else if (idx > 0)
        idx--;
    return iterator(str, old_idx);
}

iterator iterator::operator++(int){
    if (idx == END) return (*this);
    idx++;
    if (idx == str->size()) idx = END;
    return (*this);
}

iterator iterator::operator--(int){
    if (idx == END)
        idx = (int)str->size()-1;
    
    else if (idx > 0)
        idx--;
    return (*this);
}

void iterator::operator=(const iterator& it){
    str = it.str;
    idx = it.idx;
}

bool iterator::operator==(const iterator& it){
    return str == it.str && idx == it.idx;
}

bool iterator::operator!=(const iterator& it){
    return !operator==(it);
}
