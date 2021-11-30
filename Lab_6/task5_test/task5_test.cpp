#include <gtest/gtest.h>
#include "../task5/task5.h"
#include "../task5/task5.cpp"

TEST(Test1, str) {
    string str1 = "";
    string str2 = "";
    int l = 1;
    int m = 2;
    int res = 0;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test2, str) {
    string str1 = "abc";
    string str2 = "ghj";
    int l = 6;
    int m = 10;
    int res = 2;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test3, str) {
    string str1 = "abc";
    string str2 = "ghj";
    int l = 7;
    int m = 100;
    int res = 52;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test4, str) {
    string str1 = "abc";
    string str2 = "abc";
    int l = 6;
    int m = 10;
    int res = 1;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test5, str) {
    string str1 = "abc";
    string str2 = "abc";
    int l = 3;
    int m = 10;
    int res = 1;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test6, str) {
    string str1 = "abc";
    string str2 = "abc";
    int l = 1;
    int m = 10;
    int res = 0;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test7, str) {
    string str1 = "abcjjjabc";
    string str2 = "abc";
    int l = 9;
    int m = 100;
    int res = 1;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test8, str) {
    string str1 = "abc";
    string str2 = "abc";
    int l = 7;
    int m = 100;
    int res = 26;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test9, str) {
    string str1 = "aaa";
    string str2 = "aaa";
    int l = 1;
    int m = 10;
    int res = 0;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}
TEST(Test10, str) {
    string str1 = "aaa";
    string str2 = "aaa";
    int l = 3;
    int m = 10;
    int res = 1;
    EXPECT_EQ(strings(str1, str2, l, m), res);
}

