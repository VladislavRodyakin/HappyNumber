
#include "gtest/gtest.h"
#include "../HappyNumberReal/Checker.hpp"
#include "../HappyNumberReal/Parser.hpp"
#include <vector>

using namespace std;
TEST(Parsing, NoErrors) {
    stringstream inp{ "1\n"
                      "7\n"
                      "13\n"
                      "1\n"
                      "2\n"
                      "  27\n"
                      "15   \n"
                      "102" };
    vector <int> inp_{ 1,7,13,1,2,27,15,102 };
    Parser p{ inp };
    for (int i : inp_) {
        ASSERT_EQ(p.getNext(), i);
    }
}
TEST(Parsing, EmptyLines) {
    stringstream inp{ "\n"
                      "7\n"
                      "\n"
                      "\n"
                      "\n"
                      "15\n"
                      "" };
    vector <int> inp_{ 7,15 };
    Parser p{ inp };
    for (int i : inp_) {
        ASSERT_EQ(p.getNext(), i);
    }
}

TEST(Parsing, EndOfFile) {
    stringstream inp{ "\n"
                      "7\n"
                      "\n"
                      "\n"
                      "\n"
                      "15\n"
                      "" };
    vector <int> inp_{ 7,15,-1 };
    Parser p{ inp };
    for (int i : inp_) {
        ASSERT_EQ(p.getNext(), i);
    }
}

TEST(Parsing, InvalidLines) {
    stringstream inp{ " 123\n"
                      "a2\n"
                      "1\n"
                      "g5\n"
                      "53wdc\n"
                      "purr\n"
                      "  123" };
    Parser p{ inp };
    ASSERT_NO_THROW(p.getNext());
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_NO_THROW(p.getNext());
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_NO_THROW(p.getNext());
    ASSERT_EQ(p.getNext(), -1);
}
TEST(HappyNum, CheckTrue) {
    vector <int> inp_{ 1, 7, 10, 13, 19, 49, 68, 70, 79, 82, 86, 97, 100, 103, 109, 129,320, 932 };
    for (int i : inp_) {
        ASSERT_TRUE(Checker::check_happines(i));
    }
}
TEST(HappyNum, CheckFalse) {
    vector<int> inp_ = { 2, 3, 4, 5, 6, 8, 9 };
    for (int i : inp_) {
        ASSERT_FALSE(Checker::check_happines(i));
    }
}

TEST(HappyAndParser, NoErrors)
{
    stringstream inp{ "1\n"
                      "7\n"
                      "13  \n"
                      "10\n"
                      "  48\n"
                      "103" };
    Parser p(inp);
    while (inp.eof()) {
        int i = p.getNext();
        ASSERT_TRUE(Checker::check_happines(i));
    }
}
TEST(HappyAndParser, EmptyLines) {
    stringstream inp{ "\n"
                      "7\n"
                      "\n"
                      "\n"
                      "\n"
                      "15\n"
                      "" };
    Parser p(inp);
    int i = p.getNext();
    ASSERT_TRUE(Checker::check_happines(i));
    i = p.getNext();
    ASSERT_FALSE(Checker::check_happines(i));

}
TEST(HappyAndParser, InvalidLines) {
    stringstream inp{ "a\n"
                      "7\n"
                      "       \n"
                      " wow\n"
                      ":3\n"
                      "15\n"
                      "" };
    Parser p(inp);
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    int i = p.getNext();
    ASSERT_TRUE(Checker::check_happines(i));
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    ASSERT_THROW(p.getNext(), std::invalid_argument);
    i = p.getNext();
    ASSERT_FALSE(Checker::check_happines(i));

}
