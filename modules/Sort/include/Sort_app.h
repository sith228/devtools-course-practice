//Copyright Kildishev Maxim 2017

#ifndef MODULES_SORT_INCLUDE_SORT_APP_H_
#define MODULES_SORT_INCLUDE_SORT_APP_H_

#include <string>

class SortApp {
 public:
     SortApp();
     std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     typedef struct {
         double length_;
         double sort_type_;
         double* array_;

     } Arguments;


};

#endif //MODULES_SORT_INCLUDE_SORT_APP_H_
