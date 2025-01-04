#include "managers/PathManager.hpp"

managers::PathManager::PathManager(char *argv[]){
    initPath(std::filesystem::current_path().string());
    
    path_ = getParentDir(argv[0]);
    if(path_.size() > 2)
        path_ = path_.substr(2, path_.size());
}

void managers::PathManager::initPath(std::string root_path){
    root_path_ = root_path;
    path_ = "";
}

std::string managers::PathManager::getParentDir(const std::string_view dir){
    std::string path{dir};
    path = trim(path, '/').substr(0, path.find_last_of("/"));
    if(path == ".")
        path = "";
    return path;
}

std::string managers::PathManager::trim(std::string str, char pattern){
    boost::trim_if(str, [pattern](char &c){
        return c == pattern;
    });
    return str;
}

std::string managers::PathManager::getRootFielPath(std::string name_file){
    return root_path_ + "/" + getFielPath(name_file);
}

std::string managers::PathManager::getFielPath(std::string name_file){
    return path_.size() > 0 ? std::string(path_ + "/" + name_file) : name_file;
}