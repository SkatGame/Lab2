// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <ostream>
#include <chrono>
#include <algorithm>
#include <functional>
#include <string>

using std::vector;
using std::pow;
using std::cout;
using std::ostream;
using std::stringstream;
using std::endl;
using std::string;

void StraightExperiment(const vector<unsigned int>& buffer, ostream& ss);
void BackExperiment(const vector<unsigned int>& buffer, ostream& ss);
void RandomExperiment(const vector<unsigned int>& buffer, ostream& ss);
void Print(const vector<unsigned int>& buffer);
vector<unsigned int> GeneratorVector(vector<double>& cache);
inline void Heating (int* arr, int& h,const double& buffer);

const int th = 1000;
const int st = 16;
const int conv = 262144;
#endif // INCLUDE_HEADER_HPP_
