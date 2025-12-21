#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(double x)
{
    return exp(x / 4.0);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<double> x(n), y(n);

    double sumfx = 0, sumy = 0, sumfx2 = 0, sumfxy = 0;

    for (int i = 0; i < n; i++)
        fin >> x[i];
    for (int i = 0; i < n; i++)
        fin >> y[i];

    for (int i = 0; i < n; i++)
    {
        double fx = f(x[i]);
        sumfx  += fx;
        sumy   += y[i];
        sumfx2 += fx * fx;
        sumfxy += fx * y[i];
    }

    double b = (n * sumfxy - sumfx * sumy) /
               (n * sumfx2 - sumfx * sumfx);

    double a = (sumy / n) - b * (sumfx / n);

    fout << sumfx << " " << sumy << " " << sumfxy << " " << sumfx2 << '\n';

    fout << "y = " << fixed << setprecision(3) << a
         << " + " << fixed << setprecision(3) << b
         << " e^(z/4)" << '\n';

    fout << "y(6) = " << a + b * f(6) << '\n';

    fin.close();
    fout.close();

    return 0;
}
