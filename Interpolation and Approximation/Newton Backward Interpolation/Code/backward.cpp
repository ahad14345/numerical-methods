#include <bits/stdc++.h>
using namespace std;

double v_cal(double u, double n)
{
    double temp = u;
    for (int i = 1; i < n; i++)
        temp *= (u + i);
    return temp;
}

int facto(int n)
{
    if (n <= 1) return 1;
    return n * facto(n - 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<double> x(n);
    for (int i = 0; i < n; i++)
    {
        double r1, r2;
        cin >> r1 >> r2;
        x[i] = (r1 + r2) / 2;
    }

    vector<vector<double>> diff(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
        cin >> diff[i][0];

    double f1, f2;
    cin >> f1 >> f2;
    double resR = (f1 + f2) / 2;

    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            diff[j][i] = diff[j][i - 1] - diff[j - 1][i - 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << diff[i][j] << " ";
        cout << '\n';
    }

    double sum = diff[n - 1][0];
    double v = (resR - x[n - 1]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++)
        sum += (v_cal(v, i) * diff[n - 1][i]) / facto(i);

    cout << "\nInterpolated value = " << sum << '\n';
    return 0;
}
