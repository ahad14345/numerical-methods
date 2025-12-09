#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(double x, vector<int> &cofs, int n)
{
    double sum {};
    for (int i = 0; i <= n; i++)
    {
        sum += cofs[n - i] * pow(x, i);
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double step = 0.45;
    double E = 10e-3;

    int n;
    cin >> n;   // reading degree from input.txt

    vector<int> cofs;

    for (int i = 0; i <= n; i++)
    {
        int x;
        cin >> x;   // reading coefficients from input.txt
        cofs.push_back(x);
    }

    cout << "Number of degrees: " << n << '\n';

    cout << "Coefficients: ";
    for (auto i : cofs)
    {
        cout << i << " ";
    }
    cout << '\n';

    cout << "Equation: ";
    for (int i = 0; i <= n; i++)
    {
        if (cofs[i] == 0) continue;

        int power = n - i;

        if (i != 0 && cofs[i] > 0) cout << "+ ";

        cout << cofs[i] << "x^" << power << " ";
    }
    cout << '\n';

    double xmax = 1;
    double mx = 0;

    for (int i = 0; i <= n; i++)
    {
        if (mx < abs(cofs[i]))
        {
            mx = abs(cofs[i]);
        }
    }

    xmax += abs(mx / cofs[n]);
    cout << "Search range: [-" << xmax << ", " << xmax << "]\n";

    double d1 = -xmax;
    double d2 = xmax;

    while (d1 < d2)
    {
        double x1 = d1;
        double x2 = d1 + step;

        if ((f(x1, cofs, n) * f(x2, cofs, n)) < 0)
        {
            cout << "Initial interval: " << x1 << " " << x2 << '\n';

            double x0;
            int i {};

            while (true)
            {
                x0 = x1 - f(x1, cofs, n) * ((x2 - x1) / (f(x2, cofs, n) - f(x1, cofs, n)));

                if (abs(x2 - x1) < E || abs(f(x0, cofs, n)) < E)
                {
                    cout << "Root: " << x0 << '\n';
                    cout << "Iterations: " << i << '\n';
                    break;
                }

                if ((f(x1, cofs, n) * f(x0, cofs, n)) < 0)
                    x2 = x0;
                else
                    x1 = x0;

                i++;
            }
            break;
        }

        d1 += step;
    }

    return 0;
}
