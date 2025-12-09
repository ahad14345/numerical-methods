#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;   // reading number of equations from input.txt

    vector<vector<double>> a(n, vector<double>(n + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> a[i][j];   // reading augmented matrix from input.txt
        }
    }

    int step = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            for (int r = i + 1; r < n; r++)
            {
                if (a[r][i] != 0)
                {
                    swap(a[i], a[r]);
                    break;
                }
            }
        }

        double temp = a[i][i];
        if (temp == 0) continue;

        for (int j = 0; j <= n; j++)
        {
            a[i][j] /= temp;
        }

        
        for (int j = i + 1; j < n; j++)
        {
            double rt = a[j][i];
            for (int k = 0; k <= n; k++)
            {
                a[j][k] -= rt * a[i][k];
            }
            cout << "After step " << step++ << ":\n";
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c <= n; c++)
                    cout << a[r][c] << " ";
                cout << '\n';
            }
            cout << '\n';
        }

        
        for (int j = i - 1; j >= 0; j--)
        {
            double rt = a[j][i];
            for (int k = 0; k <= n; k++)
            {
                a[j][k] -= rt * a[i][k];
            }
            cout << "After step " << step++ << ":\n";
            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c <= n; c++)
                    cout << a[r][c] << " ";
                cout << '\n';
            }
            cout << '\n';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (fabs(a[i][j]) < 1e-9)
                a[i][j] = 0.0;
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
        cout << "There are infinite solutions\n";
    }
    else if (none)
    {
        cout << "There are no solutions\n";
    }
    else
    {
        cout << "The system has unique solutions\n\n";

        vector<double> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = a[i][n];
        }

        cout << "Answer is: ";
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
