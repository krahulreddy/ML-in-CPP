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
        val += x[j] * theta[j];
    }
}

vector<float> GradDescent(vector<vector<float> > X, vector<float> y, vector<float> theta, float alpha, int iter)
{
//    printf("%d %d", X.size(), X[0].size());

 
    int m = y.size();
    int n = X[0].size();
    //cout<<m<<n;
    vector<int> temp(n + 1, 0);
    vector<float> prev_theta = theta;
    for(int it = 0; it < iter; it++)
    {
        for(int j = 0; j <= n; j++)
        {
            temp[j] = 0;
            for(int i = 0; i < m; i++)
            {
                //cout<<h(X[i], theta)<<"\n";
                temp[j] += (h(X[i], theta) - y[i]) * X[i][j];
            }
        }
        for(int j = 0; j <= n; j++)
        {
            theta[j] -= (alpha / m * temp[j]);
        }
        int flag = 0;
        for(int j = 0; j <= n; j++)
        {
            if(prev_theta[j] - theta[j] > 0.001);
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<it;
            return theta;
        }
    }
    return theta;
}

int classify(float n)
{
    if(n <= 1.5)
        return 1;
    if(n <= 2.5)
        return 2;
    return 3;
}

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
    vector<float> th;
    th = GradDescent(X, y, theta, 0.006, 10000);
 
    cout<<"\nPrediction vs y values\n";
    float mse = 0;
    for(int i = 0; i < X.size(); i++)
    {
        mse += abs(classify(h(X[i], th)) - y[i]);
        cout<<classify(h(X[i], th))<<" "<<y[i]<<"\n";
    }
    //mse/=X.size();
    cout<<"errors = "<<mse<<"\nAccuracy = "<<(1 - mse/X.size())*100<<"\n";

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
