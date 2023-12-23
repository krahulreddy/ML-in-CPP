#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include "helper.h"

using namespace std;

int main()
{
    int m, n;
    FILE* f;
    f = fopen("iris.csv", "r");
    fscanf(f, "%d,%d", &m, &n);
    cout<<m<<" "<<n<<'\n';
    vector <vector<float> > X(m);
    vector <float> theta(n + 1, 0);
    vector <float> y;

    for(int i = 0; i < m; i++)
    {
    //    data[i][0] = 1;
        X[i].push_back(1);
    }
    
    for(int i = 0; i < m; i ++)
    {
        float ele;
        fscanf(f, "%f,", &ele);
        for(int j = 0; j < n; j++)
        {
            float ele;
            fscanf(f, "%f,", &ele);
            //data[i][j + 1] = ele;
            //if(j != n)
                X[i].push_back(ele);
            //else
              //   y.push_back(ele);
        }
        fscanf(f, "%f", &ele);
        y.push_back(ele);
    }
    
    //printf("%d %d", X.size(), X[m - 1].size());
    


    //Gradient descent and print values
    
    cout<<"Initial theta : \n";
    for(int i = 0; i < theta.size(); i++)
        cout<<theta[i]<<" ";
    cout<<'\n';
    float alpha = 0.006;
    int iter = 10000;
    vector<float> th;
    th = GradDescent(X, y, theta, alpha, iter);
    cout<<"Trained theta : \n";
    for(int i = 0; i < th.size(); i++)
        cout<<th[i]<<" ";
    cout<<'\n';
    cout<<"\nPrediction vs y values\n";
    float error_count = 0;
    for(int i = 0; i < X.size(); i++)
    {
        error_count += abs(classify(h(X[i], th)) - y[i]);
        cout<<classify(h(X[i], th))<<" "<<y[i]<<"\n";
    }
    //mse/=X.size();
    cout<<"errors = "<<error_count<<"\nAccuracy = "<<(1 - error_count/m)*100<<"\n";

    //Print y 
    // for(int i = 0; i <= y.size(); i++)
    // {
    //     cout<<y[i]<<" ";
    // }

    
    //Print X
    // for(int j = 0; j < X.size(); j++)
    // {
    //     for(int i = 0; i < X[j].size(); i++)
    //     {
    //         cout<<X[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // printf("\n");
    
}
