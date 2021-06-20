

#ifndef PARALLELIZER_FILE_HANDLER_H
#define PARALLELIZER_FILE_HANDLER_H

#include <fstream>

class file_handler {
public:
    file_handler(std::string file_name);
    file_handler():file_name_("");


    std::string ReadLine();

private:
    std::string file_name_;
    std::ifstream file_obj_;

    std::string curr_line_;

    bool NextLine();
};


#endif
