#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <fmt/core.h>
#include <fstream>
#include <filesystem>

#define FIRST_QUARTER_END (M_PI / 2)
#define SECOND_QUARTER_END M_PI
#define THIRD_QUARTER_END (3 * M_PI / 2)
#define _2PI (2 * M_PI)

using std::vector;

double custom_sin(double, int, bool = false);

void rad_comparison(int, int, double, const std::string&);

void deg_comparison(int, int, double, const std::string&);

#endif
