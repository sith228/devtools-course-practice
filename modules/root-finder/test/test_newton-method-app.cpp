// Copyright 2017 Maxim Doronin

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/functions.h"
#include "include/newton-method-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NewtonMethodApplicationTest : public ::testing::Test {
 protected:
    //virtual void SetUp() {}

    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); i++) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    NewtonMethodApplication app_;
    Function* polinom2degree_;
    Function* polinom3degree_;
    Function* polinom4degree_;
    Function* exponent_;
    std::string output_;
};

TEST_F(NewtonMethodApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Newton Method application");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Bounds) {
    vector<string> args = {"EXPONENT", "0"};

    Act(args);

    Assert("ERROR: No bounds!");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Coefficients) {
    vector<string> args = { "EXPONENT", "0", "1", "1" };

    Act(args);

    Assert("Mismatch in the number of arguments");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"EXPONENT", "pi", "phi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Wrong_Function_Format) {
    vector<string> args = {"EXP", "0", "1", "2", "3", "4"};

    Act(args);

    Assert("Function doesn't exist");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Zero_As_First_Coeff) {
    vector<string> args = {"EXPONENT", "0", "1", "0", "3", "4"};

    Act(args);

    Assert("First coefficient can't be zero");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_No_Monotone_Function) {
    vector<string> args = { "POLINOMIAL_2_DEGREE", "-4", "4", "2", "1", "-6" };

    Act(args);

    Assert("function isnot monotone or its point");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_If_Segment_Is_Point) {
    vector<string> args = { "POLINOMIAL_2_DEGREE", "4", "4", "2", "1", "-6" };

    Act(args);

    Assert("function isnot monotone or its point");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_If_Function_Hasnt_Roots) {
    vector<string> args = { "POLINOMIAL_2_DEGREE", "3", "4", "2", "1", "-6" };

    Act(args);

    Assert("segment have not desidion");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_2_Degree) {
    vector<string> args = { "POLINOMIAL_2_DEGREE", "0", "2", "2", "1", "-6" };

    Act(args);

    Assert("Root: 1.5");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_3_Degree) {
    vector<string> args = { "POLINOMIAL_3_DEGREE", "3", "6", "1", "-1", "-16", "16" };

    Act(args);

    Assert("Root: 4");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_4_Degree) {
    vector<string> args = { "POLINOMIAL_4_DEGREE", "2.5", "3.5", "1", "1", "-9", "-9", "0" };

    Act(args);

    Assert("Root: 3");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Exponent) {
    vector<string> args = { "EXPONENT", "-1", "1", "1", "2", "-1" };

    Act(args);

    Assert("Root: 0");
}
