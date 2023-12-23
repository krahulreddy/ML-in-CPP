#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;
float h(vector<float> x, vector <float> theta);
vector<float> GradDescent(vector<vector<float> > X, vector<float> y, vector<float> theta, float alpha, int iter);
int classify(float n);
