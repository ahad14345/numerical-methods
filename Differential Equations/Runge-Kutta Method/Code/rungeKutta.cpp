#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (2*x + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x0, y0, xn, yn, h;
    cin >> x0 >> y0;
    cin >> xn;
    cin >> h;

    double interval = round((xn - x0) / h);

    double k1, k2, k3, k4, k;
    for (int i = 1; i <= interval; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);

        k = (k1 + 2*k2 + 2*k3 + k4)/6;

        yn = y0 + k;
        x0 = x0 + h;
        y0 = yn;
    }

    cout << "f(" << xn << ") = " << yn << '\n';
}
