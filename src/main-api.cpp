#include <boost/log/trivial.hpp>
#include <iostream>
#include <vector>

#include "utils.h"
#include "file_handler.h"

int main()
{
//    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
//    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
//    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
//    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
//    BOOST_LOG_TRIVIAL(error) << "An error severity message";
//    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    auto* test = new utils::file_handler("test/file_handler/code-test/test1");

    std::vector<std::string> tokens;

    auto rslt = test->ReadToken();
    while(rslt != ""){
        BOOST_LOG_TRIVIAL(info) << rslt;
        tokens.push_back(rslt);
        rslt = test->ReadToken();
    }

    BOOST_LOG_TRIVIAL(info) << "Tokenizing finished";
    

//    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;
//    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;

//    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;
//    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;


    delete test;
//    std::cout << test->ReadToken();


}