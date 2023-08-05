#include <iostream>
#include "src/lib.hpp"
int main(void){
    std::cout << "hello world\n";
    Csv* parse = new Csv("csvSample.csv");
    std::cout << parse->path;
    parse->toObjArray();
    for(int i = 0;i < parse->objectsCount;i++){
        object obj =  parse->retObj()[i];
        for (const auto& [key1, value1] : obj)
            std::cout << "obj[" << key1 <<"]" << ":"+value1  << "\n";
    }
}