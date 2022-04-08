#include <iostream>
#include <fstream>

#typedef (double)()

class Graph{
public:

};

void read_data(const std::string& fileName, uint8_t &errCode){
    std::ifstream file(fileName);
    if (!file.is_open()){
        errCode = 5;
        return;
    }
    std::string lineOfMap;
    while(std::getline(file, lineOfMap)){
        std::cout<<lineOfMap<<std::endl;
    }
}

int main() {
    uint8_t errCode;
    read_data("dane.txt", errCode);
    if(errCode != 0){
        std::cout<<(int)errCode<<std::endl;
        return 0;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
