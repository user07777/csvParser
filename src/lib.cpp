#include "lib.hpp"

auto tokenize(std::string s, std::string del = ","){
    int start, end = -1*del.size();
    std::vector<std::string> ret;
    do {
        start = end + del.size();
        end = s.find(del, start);
        ret.push_back(s.substr(start, end - start));
    } while (end != -1);
    return ret;
}
void Csv::toObjArray(){
    std::ifstream File(path);
    std::string h,str;
    std::stringstream parseHeader;
    std::vector<std::string> header;
    if(!File.is_open()){
       throw "error check if the path is correct";
        return;
    }
    getline(File,h);
    parseHeader = std::stringstream(h);
    while( parseHeader.good() ){
        std::string name;
        getline( parseHeader, name, ',' );
        header.push_back( name );
    }


    for(std::string line ; getline(File,line);){
        auto vect = tokenize(line);
        for(int i =0;  i < (int)vect.size() ;i++){
            this->Objects[i][header[i]] = vect[i];
            objectsCount++; 
        } 
    }
 }%     
