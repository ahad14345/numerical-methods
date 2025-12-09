#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(double x, vector<double>& cofs)
{
    double sum = 0;
    int n = cofs.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        sum += cofs[i] * pow(x, n - i);
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; 
    cin >> n; // reading degree of polynomial from input.txt

    vector<double> cofs(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> cofs[i]; // reading coefficients from input.txt
    }

    cout << "Polynomial: ";
    for (int i = 0; i <= n; i++)
    {
        if (i != 0 && cofs[i] >= 0) cout << "+";
        cout << cofs[i] << "x^" << n - i << " ";
    }
    cout << "\n";

    double E = 0.0001;

    double a4 = cofs[0];
    double a3 = (n >= 3 ? cofs[n - 3] : 0);
    double a2 = (n >= 2 ? cofs[n - 2] : 0);

    double xmax = sqrt(((a3/a4)*(a3/a4)) - 2 * (a2/a4));
    double d1 = xmax;
    double d2 = -xmax;

    cout << "Search interval: [" << d2 << ", " << d1 << "]\n\n";

    double step = 0.5;
    while (d1 > d2)
    {
        double x1 = d2;
        double x2 = x1 + step;

        if (f(x1, cofs) * f(x2, cofs) < 0)
        {
            cout << "Bracket found: [" << x1 << ", " << x2 << "]\n";

            int i = 0;
            double x0;

            while (1)
            {
                x0 = x1 - f(x1, cofs) * (x2 - x1) / (f(x2, cofs) - f(x1, cofs));
                if (abs(x1 - x2) < E)
                {
                    cout << "Root: " << x0 << "\n";
                    cout << "Iterations: " << i << "\n\n";
                    break;
                }
                if (f(x0, cofs) * f(x1, cofs) < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                }
                i++;
            }
        }

        d2 += step;
    }
}
