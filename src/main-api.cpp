#include <boost/log/trivial.hpp>
#include <iostream>

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

    auto* test = new utils::file_handler("../test/file_handler/non-code-test/test2");

    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;
    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;

    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;
    BOOST_LOG_TRIVIAL(info) << test->ReadToken() << std::endl;

    delete test;
//    std::cout << test->ReadToken();


}