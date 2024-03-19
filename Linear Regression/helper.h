#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<string>

float h(std::vector<float> x, std::vector <float> theta);

std::vector<float> GradDescent(std::vector<std::vector<float> > X, std::vector<float> y, std::vector<float> theta, float alpha, int iter);

int classify(float n);
