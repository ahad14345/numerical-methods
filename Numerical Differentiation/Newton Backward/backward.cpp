#include <bits/stdc++.h>
using namespace std;

double factorial(int n)
{
    double f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cout << "Num of data points:\n";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    double xp;
    cout << "Enter the targeted value:\n";
    cin >> xp;

    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];

    cout << "Backward difference table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(8) << diff[i][j] << " ";
        cout << '\n';
    }

    double h = x[1] - x[0];
    double u = (xp - x[n - 1]) / h;

    double firstDer =
        diff[n - 1][1]
        + (2 * u + 1) * diff[n - 1][2] / factorial(2)
        + (3 * u * u + 6 * u + 2) * diff[n - 1][3] / factorial(3);

    firstDer /= h;

    double secondDer =
        diff[n - 1][2]
        + (u + 1) * diff[n - 1][3];

    secondDer /= (h * h);

    cout << "f'(x) = " << firstDer << '\n';
    cout << "f''(x) = " << secondDer << '\n';

    return 0;
}

