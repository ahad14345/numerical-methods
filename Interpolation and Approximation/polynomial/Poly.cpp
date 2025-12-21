#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;

    int deg;
    fin >> deg;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
        fin >> x[i];

    for (int i = 0; i < n; i++)
        fin >> y[i];

    vector<double> sumPow(2 * deg + 1, 0);
    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= 2 * deg; j++)
        {
            sumPow[j] += xi;
            xi *= x[i];
        }
    }

    vector<double> sumXY(deg + 1, 0);
    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= deg; j++)
        {
            sumXY[j] += xi * y[i];
            xi *= x[i];
        }
    }

    vector<vector<double>> matt(deg + 1, vector<double>(deg + 2, 0));
    for (int i = 0; i <= deg; i++)
    {
        for (int j = 0; j <= deg; j++)
        {
            matt[i][j] = sumPow[i + j];
        }
        matt[i][deg + 1] = sumXY[i];
    }

    for (int i = 0; i <= deg; i++)
    {
        for (int j = i + 1; j <= deg; j++)
        {
            if (abs(matt[j][i]) > abs(matt[i][i]))
                swap(matt[i], matt[j]);
        }
        for (int j = i + 1; j <= deg; j++)
        {
            double rt = matt[j][i] / matt[i][i];
            for (int k = i; k <= deg + 1; k++)
            {
                matt[j][k] -= rt * matt[i][k];
            }
        }
    }

    vector<double> a(deg + 1, 0);
    for (int i = deg; i >= 0; i--)
    {
        a[i] = matt[i][deg + 1];
        for (int j = i + 1; j <= deg; j++)
        {
            a[i] -= matt[i][j] * a[j];
        }
        a[i] /= matt[i][i];
    }

    for (int i = 0; i <= deg; i++)
    {
        fout << "a" << i << " = " << a[i] << '\n';
    }

    // Predict
    double val;
    fin >> val;

    double ypred = 0;
    for (int i = 0; i <= deg; i++)
    {
        ypred += a[i] * pow(val, i);
    }

    fout << "y(" << val << ") = " << ypred << '\n';

    fin.close();
    fout.close();

    return 0;
}
