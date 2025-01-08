#include "managers/PathManager.hpp"

int main(int argc, char *argv[]){
    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }
    
    managers::PathManager manager("/media/tolsedum/user/IT/Поделки/path_manager/output", "public");
    std::cout << "Текущая рабочая дирриктория: " << std::filesystem::current_path() << std::endl;

    std::cout << manager.getFielPath("test.file") << std::endl;

    if(manager.changeRootDir()){
        std::cout << "Рабочая дирриктория поменялась на relative_path_: " << std::filesystem::current_path() << std::endl;
        std::cout << manager.getFielPath("test.file") << std::endl;
        if(manager.bakToOldRootDir()){
            std::cout << "Вернули прежнюю рабочую директорию: " << std::filesystem::current_path() << std::endl;
            std::cout << manager.getFielPath("test.file") << std::endl;
        }else{
            std::cout 
                << "Либо директория уже переключина либо не существует"
            << std::endl;
        }
    }else{
        std::cout 
            << "Либо директория уже переключина либо не существует"
        << std::endl;
    }
    return 0;
}