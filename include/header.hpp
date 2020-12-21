// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <ostream>
#include <chrono>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <functional>

using std::vector;
using std::pow;
using std::cout;
using std::ostream;
using std::stringstream;
using std::endl;
using std::set;

void StraightExperiment(const vector<unsigned int>& buffer);
void BackExperiment(const vector<unsigned int>& buffer);
void RandomExperiment(const vector<unsigned int>& buffer);
void Print(const vector<unsigned int>& buffer);
vector<unsigned int> GeneratorVector(vector<double>& cache);

const int th = 1000;
const int st = 16;
const int conv = 262144;
#endif // INCLUDE_HEADER_HPP_
