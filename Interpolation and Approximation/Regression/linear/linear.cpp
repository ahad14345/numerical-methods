
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
        fin >> x[i];

    for (int i = 0; i < n; i++)
        fin >> y[i];

    double sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;

    for (int i = 0; i < n; i++)
    {
        sumx  += x[i];
        sumy  += y[i];
        sumx2 += x[i] * x[i];
        sumxy += x[i] * y[i];
    }

    double b = (n * sumxy - sumx * sumy) /
               (n * sumx2 - sumx * sumx);

    double a = (sumy / n) - b * (sumx / n);

    fout << "a = " << a << '\n';
    fout << "b = " << b << '\n';

    fout << "Linear equation: y = "
         << a << " + " << b << "x" << '\n';

    double val;
    fin >> val;

    double ypred = a + b * val;
    fout << "y(" << val << ") = " << ypred << '\n';

    fin.close();
    fout.close();

    return 0;
}
