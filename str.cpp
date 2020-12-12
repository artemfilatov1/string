#include "str.hpp"
#include "iter.hpp"

#define END -1

STRING::STRING(){
    empty = true;
    size_s = 0;
}

STRING::STRING(char * str_){
    empty = false;
    size_s = (unsigned int)strlen(str_);
    str = strdup(str_);
}

STRING::~STRING(){
    if (!empty){
        empty = true;
        free(str);
        size_s = 0;
    }
}

char * STRING::c_str(){
    return str;
}
unsigned int STRING::size() const{
    return size_s;
}

void STRING::operator = (char* s){
    if (!empty){
        free(str);
    }
    size_s = (unsigned int)strlen(s);
    str = strdup(s);
    empty = false;
}

char STRING::operator [](int idx){
    return str[idx];
}

iterator STRING::begin(){
    return iterator(this, 0);
}

iterator STRING::end(){
    return iterator(this, END);
}

void STRING::erase(const iterator& it){
    char* tmp = (char*)malloc(size_s-1);
    
    int cnt = 0;
    for (int i = 0; i < size_s; i++){
        if (i != it.idx){
            tmp[cnt] = str[i];
            cnt++;
        }
    }
    free(str);
    
    str = tmp;
    size_s--;
}

void STRING::push_back(const char& c){
    size_s++;
    char* tmp = (char*)malloc(size_s+1);
    strcpy(tmp, str);
    
    tmp[size_s-1] = c;
    tmp[size_s] = 0;
    free(str);
    
    str = tmp;
}
