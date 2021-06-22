

#ifndef PARALLELIZER_FILE_HANDLER_H
#define PARALLELIZER_FILE_HANDLER_H

#include <fstream>
#include "utils.h"

class utils::file_handler {
public:
    explicit file_handler(std::string file_name);
    file_handler() = default;

    std::string ReadToken();

private:
    std::string file_name_;
    std::ifstream file_obj_;
    std::streambuf *file_pbuf_;

    std::string curr_token_;

    bool NextToken();
};


#endif
