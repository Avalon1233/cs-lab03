#include "histogram.h"
#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({ -1, -2, -3 }, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same_numbers() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_one_elem() {
    double min = 0;
    double max = 0;
    find_minmax({ 1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void check_red_color() {
    bool answer = check_color("red");
    assert(answer == false);
}

void check_blue_color() {
    bool answer = check_color("blue");
    assert(answer == true);
}

int main() {
    test_positive();
    test_negative();
    test_same_numbers();
    test_one_elem();
    test_empty();
    check_red_color();
    check_blue_color();
}