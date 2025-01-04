#include "managers/PathManager.hpp"

int main(int argc, char *argv[]){
    managers::PathManager manager(argv);
    std::cout 
        << "root path: " << manager.getRootPath() 
        << std::endl
        << "current path: " << manager.getCurrentPath()
        << std::endl
        << "file path: " << manager.getFielPath("file.txt")
        << std::endl
        << "file root path: " << manager.getRootFielPath("file.txt")
    << std::endl;

    return 0;
}
