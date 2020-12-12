#include <iostream>
#include <string>
#include "str.hpp"
#include "iter.hpp"

//using namespace std;

int main(int argc, const char * argv[]) {
    STRING s = (char*)"123";

    s.push_back('4');
    
    std::cout << s.c_str() << std::endl;
    
    return 0;
}
