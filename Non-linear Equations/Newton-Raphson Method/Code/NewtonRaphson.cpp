#include <bits/stdc++.h>
using namespace std;

double f(double x, vector<int> &cofs, int n)
{
    double sum {};
    for (int i = 0; i <= n; i++)
    {
        sum += cofs[i] * pow(x, n - i);
    }
    return sum;
}

double df(double x, vector<int> &cofs2, int n)
{
    double sum {};
    for (int i = 0; i <= n - 1; i++)
    {
        sum += cofs2[i] * pow(x, n - i);
    }
    return sum;
}

void printPolynomial(vector<int>& cofs)
{
    int n = cofs.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        if (cofs[i] == 0) continue;
        if (i != 0 && cofs[i] > 0) cout << "+";
        cout << cofs[i];
        if (n - i > 1) cout << "x^" << n - i;
        else if (n - i == 1) cout << "x";
        cout << " ";
    }
    cout << "= 0\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double E = 10e-3;
    double step = 0.45;
    int n;
    cout << "No. of degree of the equation: ";
    cin >> n;

    vector<int> cofs(n + 1);
    cout << "Coefficients of the equation: ";
    for (int i = 0; i <= n; i++)
        cin >> cofs[i];

    printPolynomial(cofs);

    vector<int> cofs2(n);
    for (int i = 0; i < n; i++)
        cofs2[i] = cofs[i] * (n - i);

    cout << "Derivative: ";
    printPolynomial(cofs2);

    double xmax = 1, mx {};
    for (int i = 0; i <= n; i++)
        if (mx < abs(cofs[i]))
            mx = abs(cofs[i]);
    xmax += abs(mx / cofs[0]);

    double d1 = -xmax;
    double d2 = xmax;

    while (d1 < d2)
    {
        double x1 = d1;
        double x2 = d1 + step;
        double f1 = f(x1, cofs, n);
        double f2 = f(x2, cofs, n);

        if ((f1 * f2) < 0)
        {
            double x0;
            int i = 0;
            cout << "\nBracket found: [" << x1 << ", " << x2 << "]\n";

            while (true)
            {
                x0 = x1 - (f(x1, cofs, n)) / (df(x1, cofs2, n - 1));
                if ((abs(x0 - x1) < E) && (abs(f(x0, cofs, n)) < E))
                {
                    cout << "Root: " << x0 << "\n";
                    cout << "Iteration number: " << i << "\n";
                    break;
                }
                x1 = x0;
                i++;
            }
        }
        d1 += step;
    }

    return 0;
}
