#include <bits/stdc++.h>
#include <cmath>

using namespace std;

double f(double x)
{
    return (1/(1 + (x*x)));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, interval, h, ans = 0;

    cin >> a >> b >> interval;

    h = (b - a) / interval;
    ans = f(a) + f(b);

    cout << "Lower limit a: " << a << '\n';
    cout << "Upper limit b: " << b << '\n';
    cout << "Number of intervals: " << interval << '\n';
    cout << "Step size h: " << h << "\n\n";

    for (int i = 1; i < interval; i++)
    {
        double x = a + (i * h);
        if (i % 2 == 0)
            ans += 2 * f(x);
        else
            ans += 4 * f(x);
    }

    ans = ans * h / 3;

    cout << "Integration of the function: " << setprecision(5) << ans << '\n';
}
