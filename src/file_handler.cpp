//
// Created by mahee on 2021-06-19.
//
#include <boost/log/trivial.hpp>
#include <string>
#include <utility>
#include "file_handler.h"

std::string utils::file_handler::ReadLine() {
/**
 * Returns the next line in file.
 * Increments to next line using NextLine()
 *
 * @return: next line as a string, null if next line if file end.
 */
    if (!this->file_obj_.is_open()){
        BOOST_LOG_TRIVIAL(debug) << "Attempting to read closed file. returning nullptr";
        return nullptr;
    }
    auto rslt = this->curr_line_;

    if (!NextLine()){
        BOOST_LOG_TRIVIAL(info) << "Reached end of file, returning last line. Closing file.";
        this->file_obj_.close();
    }

    return rslt;
}

utils::file_handler::file_handler(std::string file_name) : file_name_(std::move(file_name)) {
    BOOST_LOG_TRIVIAL(info) << "attempting to open file: " << file_name_;
    this->file_obj_.open(this->file_name_);
    if (!this->file_obj_) {
        BOOST_LOG_TRIVIAL(fatal) << "Unable to open file: " << file_name_ << "\nExiting";
        exit(EXIT_FAILURE);
    }
    this->NextLine();
}

bool utils::file_handler::NextLine() {
    auto retval = this->file_obj_.peek() != EOF;
    getline(this->file_obj_, this->curr_line_);
    return retval;
}

