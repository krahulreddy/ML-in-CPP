#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;

float h(vector<float> x, vector <float> theta)
{
    float val = 0;
    for(int j = 0; j < x.size(); j++)
    {
        val += (x[j] * theta[j]);
    }
    return val;
}

vector<float> GradDescent(vector<vector<float> > X, vector<float> y, vector<float> theta, float alpha, int iter)
{
    int m = y.size();
    int n = X[0].size() - 1;
    //cout<<m<<n;
    vector<int> temp(n, 0);
    //vector<float> prev_theta = theta;
    for(int it = 0; it < iter; it++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int i = 0; i < m; i++)
            {
                //cout<<h(X[i], theta)<<"\n";
                temp[j] += (h(X[i], theta) - y[i]) * X[i][j];
            }
        }
        for(int j = 0; j <= n; j++)
        {
            //if(iter % 10000 == 0)
              //  cout<<theta[j]<<" ";
            theta[j] -= (alpha / m * temp[j]);
        }
        //if(iter % 10000 == 0)
          //  cout<<"\n";
    }
    return theta;
}

int main()
{
    vector <vector<float> > X;
    vector <float> theta{0,0,0,0,0};
    vector <float> temp0{1,1,1,2,95};
    vector <float> temp1{1,95,3,2,9};
    vector <float> temp2{1,5,100,2,3};
    vector <float> temp3{1,0,0,99,3};
    X.push_back(temp0);
    X.push_back(temp1);
    X.push_back(temp2);
    X.push_back(temp3);
    vector <float> y{99, 109, 111, 102};
    vector<float> th;
    th = GradDescent(X, y, theta, 0.0001, 10000);
    cout<<"Predicted theta values : \n";
    for(int i = 0; i < th.size(); i++)
    {
        cout<<th[i]<<" ";
    }
    cout<<"\nPrediction vs y values\n";
    float mse = 0;
    for(int i = 0; i < X.size(); i++)
    {
        mse += pow(h(X[i], th) - y[i], 2);
        cout<<h(X[i], th)<<" "<<y[i]<<"\n";
    }
    mse/=X.size();
    cout<<"Mean Square error = "<<mse<<"\n";
    return 0;
}
