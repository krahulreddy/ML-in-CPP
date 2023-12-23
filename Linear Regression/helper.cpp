#include "helper.h"


float h(std::vector<float> x, std::vector <float> theta)
{
    float val = 0;
    for(int j = 0; j < x.size(); j++)
    {
        val += x[j] * theta[j];
    }
    return val;
}

std::vector<float> GradDescent(std::vector<vector<float> > X, std::vector<float> y, std::vector<float> theta, float alpha, int iter)
{
//    printf("%d %d", X.size(), X[0].size());

 
    int m = y.size();
    int n = X[0].size();
    //cout<<m<<n;
    std::vector<int> temp(n + 1, 0);
    std::vector<float> prev_theta = theta;
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
            if(prev_theta[j] - theta[j] > 0.001)
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
