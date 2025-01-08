#ifndef PATH_MANAGER_HPP
#define PATH_MANAGER_HPP

/** Version 2.0 */

/**
 *  __________________________________________
 * |                                          |
 * |   ╭━━━━┳━━━┳╮╱╱╭━━━┳━━━┳━━━┳╮╱╭┳━╮╭━╮    |
 * |   ┃╭╮╭╮┃╭━╮┃┃╱╱┃╭━╮┃╭━━┻╮╭╮┃┃╱┃┃┃╰╯┃┃    |
 * |   ╰╯┃┃╰┫┃╱┃┃┃╱╱┃╰━━┫╰━━╮┃┃┃┃┃╱┃┃╭╮╭╮┃    |
 * |   ╱╱┃┃╱┃┃╱┃┃┃╱╭╋━━╮┃╭━━╯┃┃┃┃┃╱┃┃┃┃┃┃┃    |
 * |   ╱╱┃┃╱┃╰━╯┃╰━╯┃╰━╯┃╰━━┳╯╰╯┃╰━╯┃┃┃┃┃┃    |
 * |   ╱╱╰╯╱╰━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻╯╰╯╰╯    |
 * |__________________________________________|
 * |                                          |
 * | Permission is hereby granted, free of    |
 * | charge, to any person obtaining a copy of|
 * | of this software and accompanying files, |
 * | to use them without restriction,         |
 * | including, without limitation, the       |
 * | rights to use, copy, modify, merge,      |
 * | publish, distribute, sublicense and/or   |
 * | sell copies of the software. The authors |
 * | or copyright holders shall not be liable |
 * | for any claims, damages or other         |
 * | liability, whether in contract, tort or  |
 * | otherwise, arising out of or in          |
 * | connection with the software or your use |
 * | or other dealings with the software.     |
 * |__________________________________________|
 * |   website: tolsedum.ru                   |
 * |   email: tolsedum@gmail.com              |
 * |   email: tolsedum@yandex.ru              |
 * |__________________________________________|
 */

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <filesystem>
#include <map>

namespace managers{
    class PathManager{
        /** @brief Old working directory */
        std::string old_root_path_;
        /** @brief The program's working directory */
        std::string root_path_;
        /** @brief The directory is relative to the main one (root_path_/relative_path_) */
        std::string relative_path_;

        bool changeCurrentDir(std::string_view dir);

    public:
        PathManager(std::string_view root, std::string_view relative)
            {initPath(root, relative);};
        PathManager(){};
        ~PathManager(){};

        void initPath(
            std::string_view root, 
            std::string_view relative = ""
        );

        bool changeRootDir();
        bool bakToOldRootDir();

        std::string getFielPath(std::string_view file_name);
        
        std::string getRootPath(){return root_path_;};
        std::string getRelativePath(){return relative_path_;};
    };
}

#endif /* PATH_MANAGER_HPP */
