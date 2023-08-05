#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <unordered_map>

#define N (1 << 14)
typedef std::unordered_map<std::string, std::string> object;

class Csv{
    public:
        Csv(std::string  path_){
        this->path = path_;
        }
        std::string path;

        void toObjArray();
        auto retObj() {
            return Objects;
        };
        int objectsCount =0;
    private:
        object Objects[N];
};

