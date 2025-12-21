#include <iostream>
#include <vector>
using namespace std;

void makeCofactor(vector<vector<int>>& a, vector<vector<int>>& temp,
                  int r, int c, int sz)
{
    int x = 0, y = 0;
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (i != r && j != c)
            {
                temp[x][y++] = a[i][j];
                if (y == sz - 1)
                {
                    y = 0;
                    x++;
                }
            }
        }
    }
}

int determinant(vector<vector<int>>& a, int sz)
{
    if (sz == 1)
        return a[0][0];

    int ans = 0;
    vector<vector<int>> temp(sz, vector<int>(sz));
    int sign = 1;

    for (int f = 0; f < sz; f++)
    {
        makeCofactor(a, temp, 0, f, sz);
        ans += sign * a[0][f] * determinant(temp, sz - 1);
        sign = -sign;
    }
    return ans;
}

void getAdjoint(vector<vector<int>>& a, vector<vector<int>>& adj)
{
    int sz = a.size();
    if (sz == 1)
    {
        adj[0][0] = 1;
        return;
    }

    vector<vector<int>> temp(sz, vector<int>(sz));
    int sign;

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            makeCofactor(a, temp, i, j, sz);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, sz - 1);
        }
    }
}

bool findInverse(vector<vector<int>>& a, vector<vector<float>>& inv)
{
    int sz = a.size();
    int det = determinant(a, sz);

    if (det == 0)
    {
        cout << "Inverse does not exist\n";
        return false;
    }

    vector<vector<int>> adj(sz, vector<int>(sz));
    getAdjoint(a, adj);

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            inv[i][j] = adj[i][j] / float(det);

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    vector<vector<int>> adj(n, vector<int>(n));
    vector<vector<float>> inv(n, vector<float>(n));

    cout << "Matrix:\n";
    for (auto &r : matrix)
    {
        for (int v : r)
            cout << v << " ";
        cout << "\n";
    }

    cout << "\nAdjoint matrix:\n";
    getAdjoint(matrix, adj);
    for (auto &r : adj)
    {
        for (int v : r)
            cout << v << " ";
        cout << "\n";
    }

    cout << "\nInverse matrix:\n";
    if (findInverse(matrix, inv))
    {
        for (auto &r : inv)
        {
            for (float v : r)
                cout << v << " ";
            cout << "\n";
        }
    }

    return 0;
}
