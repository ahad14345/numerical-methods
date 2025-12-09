#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (true)
    {
        int n;
        cin >> n;   // reading number of equations from input.txt

        vector<vector<double>> a(n, vector<double>(n + 1));
        vector<double> ans(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cin >> a[i][j];   // reading augmented matrix from input.txt
            }
        }

        int step = 1;

        for (int i = 0; i < n; i++)
        {
            if (a[i][i] == 0) continue;

            for (int j = i + 1; j < n; j++)
            {
                double rt = a[j][i] / a[i][i];

                for (int k = 0; k <= n; k++)
                {
                    a[j][k] -= rt * a[i][k];
                }

                cout << "After step " << step++ << ":\n\n";

                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < n + 1; c++)
                    {
                        cout << a[r][c] << " ";
                    }
                    cout << '\n';
                }
                cout << '\n';
            }
        }

        bool inf = false, none = false;

        for (int i = 0; i < n; i++)
        {
            bool allZero = true;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != 0)
                {
                    allZero = false;
                    break;
                }
            }

            if (allZero && a[i][n] == 0) inf = true;
            else if (allZero && a[i][n] != 0) none = true;
        }

        if (inf)
        {
            cout << "There are infinite solutions\n\n";
        }
        else if (none)
        {
            cout << "There are no solutions\n\n";
        }
        else
        {
            cout << "The system has unique solutions\n\n";

            for (int i = n - 1; i >= 0; i--)
            {
                double sum = a[i][n];

                for (int j = i + 1; j < n; j++)
                {
                    sum -= a[i][j] * ans[j];
                }

                ans[i] = sum / a[i][i];
            }

            for (int i = 0; i < n; i++)
            {
                cout << "x" << i + 1 << " = " << ans[i] << '\n';
            }
        }

        char con;
        cin >> con;

        if (con == 'n')
        {
            break;
        }
    }

    return 0;
}
