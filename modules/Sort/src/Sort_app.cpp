//Copyright Kildishev Maxim 2017

#include "include/Sort_app.h"
#include "include/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <sstream>

SortApp::SortApp() : message_("") {}

void SortApp::help(const char* appname, const char* message) {
    message_ = string(message) +
        "This is a sort application. \n\n" +
        "Pleass provide arguments in the following format:\n\n";


}
