#pragma once
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string> 

using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x = 0, double y = 0, double width = 100, double height = 200, string stroke = "black", string fill = "black");
void show_histogram_svg(const vector<size_t>& bins, string column_color);
bool check_color(string color);
string input_color_svg();
void svg_header(const size_t width, const size_t baseline, string text);