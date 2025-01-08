#include "managers/PathManager.hpp"

void managers::PathManager::initPath(std::string_view root, std::string_view relative){
    root_path_ = root;
    relative_path_ = relative;
}

bool managers::PathManager::changeCurrentDir(std::string_view dir){
    bool is_changing = false;
    if(std::filesystem::current_path() != dir && std::filesystem::exists(dir)){
        std::filesystem::current_path(dir);
        is_changing = true;
    }
    return is_changing;
}

bool managers::PathManager::changeRootDir(){
    std::string tmp = std::filesystem::current_path();
    if(changeCurrentDir(root_path_)){
        old_root_path_ = tmp;
        if(old_root_path_.empty()){
            old_root_path_ = "/";
        }
        return true;
    }
    return false;
}

bool managers::PathManager::bakToOldRootDir(){
    return changeCurrentDir(old_root_path_);
}

std::string managers::PathManager::getFielPath(std::string_view file_name){
    if(std::filesystem::current_path() != root_path_){
        return relative_path_.empty() 
            ? root_path_ + "/" + std::string(file_name) 
            : root_path_ + "/" + relative_path_ + "/" + std::string(file_name);
    }else{
        return relative_path_.empty() 
            ? std::string(file_name) 
            : relative_path_ + "/" + std::string(file_name);
    }
}