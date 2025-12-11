#include <bits/stdc++.h>
#include <cmath>

using namespace std;

double f(double x)
{
    return (pow(x, 0.5));
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
        if (i % 3 == 0)
            ans += 2 * f(x);
        else
            ans += 3 * f(x);
    }

    ans = ans * (3 * h) / 8;

    cout << "Integration of the function: " << setprecision(5) << ans << '\n';
}
