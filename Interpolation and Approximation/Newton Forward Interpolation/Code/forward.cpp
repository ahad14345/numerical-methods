#include <bits/stdc++.h>
using namespace std;

double u_cal(double u, double i)
{
    double temp = 1;
    for (int j = 0; j < i; j++)
        temp *= (u - j);
    return temp;
}

int facto(int x)
{
    if (x <= 1) return 1;
    return x * facto(x - 1);
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
        for (int j = 0; j < n - i; j++)
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << diff[i][j] << " ";
        cout << '\n';
    }

    double sum = diff[0][0];
    double u = (resR - x[0]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++)
        sum += (u_cal(u, i) * diff[0][i]) / facto(i);

    cout << "\nInterpolated value = " << sum << '\n';
    return 0;
}
