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
    for (double &v : x) cin >> v;

    cout << "Enter y values:\n";
    for (double &v : y) cin >> v;

    double xp;
    cout << "Enter the targeted value:\n";
    cin >> xp;

    vector<vector<double>> d(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        d[i][0] = y[i];

    for (int col = 1; col < n; col++)
        for (int row = 0; row < n - col; row++)
            d[row][col] = d[row + 1][col - 1] - d[row][col - 1];

    cout << "Forward difference table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << setw(8) << d[i][j] << " ";
        cout << '\n';
    }

    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;

    double firstDer =
        d[0][1]
        + (2 * u - 1) * d[0][2] / factorial(2)
        + (3 * u * u - 6 * u + 2) * d[0][3] / factorial(3);

    firstDer /= h;

    double secondDer =
        d[0][2]
        + (u - 1) * d[0][3];

    secondDer /= (h * h);

    cout << "f'(x) = " << firstDer << '\n';
    cout << "f''(x) = " << secondDer << '\n';

    return 0;
}

