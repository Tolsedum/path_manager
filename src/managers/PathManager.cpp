#include "managers/PathManager.hpp"

managers::PathManager::PathManager(char *argv[]){
    initPath(std::filesystem::current_path().string());
    initByPath(argv[0]);
}

managers::PathManager::PathManager(std::string arg){
    initPath(std::filesystem::current_path().string());
    initByPath(arg);
}


void managers::PathManager::initPath(std::string root_path){
    root_path_ = root_path;
    path_ = "";
}

void managers::PathManager::initByPath(std::string_view path){
    if(path.empty()){
        path_ = "";
    }else{
        path_ = getParentDir(path);
        if(path_.size() > 2){
            if(path[0] == '/'){
                path_ = "";
                root_path_ = path;
            }else if((path_[0] == '.' && path_[1] == '/')){
                path_ = path_.substr(2, path_.size());
            }
        }
    }
}

void managers::PathManager::setCurrentPath(std::string new_path){
    path_ = trim(new_path, '/');
}
std::string managers::PathManager::getParentDir(const std::string_view dir)
{
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
    name_file = trim(name_file, '/');
    return path_.size() > 0 ? std::string(path_ + "/" + name_file) : name_file;
}