//
// Created by mahee on 2021-06-19.
//
#include <boost/log/trivial.hpp>
#include <string>
#include <utility>
#include "file_handler.h"

bool isReserved(char c) {
    
    return !isalnum(c) && c != '_';

}

bool isWhiteSpace(char c) {

    return c == ' ' || c == '\t' || c == '\n';

}

std::string utils::file_handler::ReadToken() {
/**
 * Returns the next line in file.
 * Increments to next line using NextToken()
 *
 * @return: next line as a string, empty if file end
 */
    if (!this->file_obj_.is_open()){
        BOOST_LOG_TRIVIAL(debug) << "Attempting to read closed file. returning empty string";
        this->curr_token_ = "";
        return this->curr_token_;
    }
    auto rslt = this->curr_token_;

    if (!this->NextToken()){
        BOOST_LOG_TRIVIAL(debug) << "Reached end of file, returning last token. Closing file.";
        this->file_obj_.close();
    }

    return rslt;
}

std::string utils::file_handler::PeakToken() {
    /**
     *
     * Returns the curr_token_ 
     *
     * @return: curr_token_
     */

    if (!this->file_obj_.is_open()){
        BOOST_LOG_TRIVIAL(debug) << "Attempting to read closed file. returning empty string";
        this->curr_token_ = "";
    }

    return this->curr_token_;
    
}

utils::file_handler::file_handler(std::string file_name) : file_name_(std::move(file_name)) {
    BOOST_LOG_TRIVIAL(info) << "attempting to open file: " << file_name_;
    this->file_obj_.open(this->file_name_);
    if (!this->file_obj_) {
        BOOST_LOG_TRIVIAL(fatal) << "Unable to open file: " << file_name_ << "\nExiting";
        exit(EXIT_FAILURE);
    }
    else{
        this->file_pbuf_ = this->file_obj_.rdbuf();
    }
    this->NextToken();
}

bool utils::file_handler::NextToken() {

    std::string tmpStr = "";
    // Remove leading whitespace
    while(this->file_pbuf_->sgetc() != EOF && isWhiteSpace(this->file_pbuf_->sgetc())){
        this->file_pbuf_->sbumpc();
    }
    // Reached end of file
    if(this->file_pbuf_->sgetc() == EOF){
        return false;
    }
    if(!isReserved(this->file_pbuf_->sgetc())){
        // regular alphanumeric values and _
        while(this->file_pbuf_->sgetc() != EOF && !isReserved(this->file_pbuf_->sgetc())){
            tmpStr += this->file_pbuf_->sbumpc();
        }
        this->curr_token_ = std::move(tmpStr);
    }
    else{
        // Reserved character
        this->curr_token_ = this->file_pbuf_->sbumpc();
    }
    return true;
}

