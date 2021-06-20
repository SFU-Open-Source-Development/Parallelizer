//
// Created by mahee on 2021-06-19.
//

#include <string>
#include <utility>
#include "file_handler.h"

std::string file_handler::ReadLine() {
/**
 * Returns the next line in file.
 * Increments to next line using NextLine()
 *
 * @return: next line as a string, null if next line if file end.
 */

}

bool file_handler::NextLine() {
    return false;
}

file_handler::file_handler(std::string file_name) : file_name_(std::move(file_name)) {
    this->file_obj_.open(this->file_name_);

    if (!this->file_obj_){

    }
}
