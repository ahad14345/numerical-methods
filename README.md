# Course CSE 2208 – Numerical Methods Lab

This is the repo for the project of CSE 2209 (Numerical Methods Laboratory)
Our group members are -

1. Sabyasachi Sadhu Turjo - 2207093
2. Bikon Ghosh - 2207100
3. Sheikh MD Ahad Al Nabil - 2207120

## About This Project

This project is a collection of basic numerical methods written in C++ for the Numerical Methods Lab course. Numerical methods are used when mathematical problems are too difficult to solve exactly, so approximate solutions are needed.

In this repository, different techniques are implemented to solve linear equations, non-linear equations, interpolation, numerical differentiation, numerical integration, curve fitting, and ordinary differential equations. Each method includes its theory, source code, and sample input and output to help understand how it works.

## Table of Contents

### 1. [Linear Equations](#linear-equations)

- [**Gauss Elimination**](#gauss-elimination-method)

  - [Theory](#theory)
  - [Code](#code)
  - [Input](#sample-input)
  - [Output](#sample-output)

- [**Gauss Jordan Elimination**](#gauss-jordan-method)

  - [Theory](#theory-1)
  - [Code](#code-1)
  - [Input](#sample-input-1)
  - [Output](#sample-output-1)

- **LU Decomposition**

  - Theory
  - Code
  - Input
  - Output

- **Matrix Inversion**
  - Theory
  - Code
  - Input
  - Output

---

### 2.Non-Linear Equations

- **Bisection Method**

  - Theory
  - Code
  - Input
  - Output

- **False Position Method**

  - Theory
  - Code
  - Input
  - Output

- **Newton Raphson Method**

  - Theory
  - Code
  - Input
  - Output

- **Secant Method**
  - Theory
  - Code
  - Input
  - Output

---

### 3. Interpolation and Approximation

- **Newton Forward Interpolation**

  - Theory
  - Code
  - Input
  - Output

- **Newton Backward Interpolation**
  - Theory
  - Code
  - Input
  - Output

---

### 4. Curve Fitting

- **Exponential Regression**

  - Theory
  - Code
  - Input
  - Output

- **Linear Regression**

  - Theory
  - Code
  - Input
  - Output

- **Polynomial Regression**
  - Theory
  - Code
  - Input
  - Output

---

### 5. Numerical Differentiation

- **Newton Forward Difference**

  - Theory
  - Code
  - Input
  - Output

- **Newton Backward Difference**
  - Theory
  - Code
  - Input
  - Output

---

### 6. Numerical Integration

- **Simpson’s 1/3 Rule**

  - Theory
  - Code
  - Input
  - Output

- **Simpson’s 3/8 Rule**
  - Theory
  - Code
  - Input
  - Output

---

### 7. Ordinary Differential Equations

- **Runge-Kutta Method (4th Order)**
  - Theory
  - Code
  - Input
  - Output

---

# Linear Equations

---

## Gauss Elimination Method

### Theory

The Gauss Elimination method transforms a system of linear equations into an Upper Triangular Matrix form. This allows us to find the values of the unknowns (x1,x2,x3....xn) using Back Substitution.
A system of linear equations can be written as:

AX = B

Where:

- \(A\) is the coefficient matrix
- \(X\) is the matrix of unknown variables
- \(B\) is the constant matrix

The process involves two main phases:

Forward Elimination: Using row operations to make all elements below the main diagonal zero.

Back Substitution: Starting from the last equation (which now has only one unknown), we solve for each variable one by one.

### Algorithm / Steps (with Mathematical Expressions)

1. **Input the matrix**  
   Read the augmented matrix into a 2D array  
   a[i][j], i = 1....n; j = 1 .... n+1

2. **Select the pivot element**  
   For each row i, choose the diagonal element:
   pivot = a[i][i]

3. **Make the pivot equal to 1**  
   Divide the entire row by the pivot element:
   a[i][j] = a[i][j]/pivot, for all j

4. **Make other elements of the column zero**  
   For all rows:
   a[k][j] = a[k][j] - a[k][i] \* a[i][j]

5. **Back Substitution**
   Check if a[n][n]=0; if yes, the system may have no unique solution.
   if no,Initialize x[n]= a[n][n+1] / a[n][n].For i = n-1 down to 1, Sum = 0.
   For j = i+1 to n.Sum = Sum + a[i][j] X x[j].x[i] = (a[i][n+1] - Sum) / a[i][i].

6. **Obtain the solution**  
   Display the values of x1,x2....,xn

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
n
```

## Sample Output:

```cpp
After step 1:

2 1 -1 8
0 0.5 0.5 1
-2 1 2 -3

After step 2:

2 1 -1 8
0 0.5 0.5 1
0 2 1 5

After step 3:

2 1 -1 8
0 0.5 0.5 1
0 0 -1 1

The system has unique solutions

x1 = 2
x2 = 3
x3 = -1
```

## [Back to Top](#about-this-project)

---

## Gauss Jordan Method

### Theory

The Gauss–Jordan method is a simple and systematic technique used to solve a system of linear equations. In numerical methods, the equations are represented in the form of an augmented matrix, which is stored as a 2D array in programming languages like **C++**.

A system of linear equations can be written as:

AX = B

Where:

- \(A\) is the coefficient matrix
- \(X\) is the matrix of unknown variables
- \(B\) is the constant matrix

The goal of the Gauss–Jordan method is to convert this matrix into **reduced row-echelon form**, where:

- The diagonal elements become 1
- All other elements in each pivot column become 0
- Each row represents one variable clearly

After this transformation, the solution is obtained directly from the last column of the matrix.

---

### Algorithm / Steps (with Mathematical Expressions)

1. **Input the matrix**  
   Read the augmented matrix into a 2D array  
   a[i][j], i = 1....n; j = 1 .... n+1

2. **Select the pivot element**  
   For each row i, choose the diagonal element:
   pivot = a[i][i]

3. **Make the pivot equal to 1**  
   Divide the entire row by the pivot element:
   a[i][j] = a[i][j]/pivot, for all j

4. **Make other elements of the column zero**  
   For all rows:
   a[k][j] = a[k][j] - a[k][i] \* a[i][j]

5. **Repeat for all rows**  
   Continue steps 2 to 4 for i = 1.... n until the matrix becomes:
   [I|X]
   where \(I\) is the identity matrix.

6. **Obtain the solution**  
   The values of the variables are:

   x[i] = a[i][n+1]

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
```

## Sample Output:

```cpp
After step 1:
1 0.5 -0.5 4
0 0.5 0.5 1
-2 1 2 -3

After step 2:
1 0.5 -0.5 4
0 0.5 0.5 1
0 2 1 5

After step 3:
1 0.5 -0.5 4
0 1 1 2
0 0 -1 1

After step 4:
1 0 -1 3
0 1 1 2
0 0 -1 1

After step 5:
1 0 -1 3
0 1 0 3
-0 -0 1 -1

After step 6:
1 0 0 2
0 1 0 3
-0 -0 1 -1

The system has unique solutions

Answer is: 2 3 -1
```

## [Back to Top](#about-this-project)

---
## LU Decomposition

### Theory
LU Decomposition (or LU Factorization) is a method to solve a system of linear equations by breaking down a square matrix into two simpler parts:

1. L (Lower Triangular Matrix): A matrix where all the numbers above the main diagonal are zero.
2. U (Upper Triangular Matrix): A matrix where all the numbers below the main diagonal are zero.
Instead of solving one hard problem Ax = b, we turn it into two easy problems involving triangles.

### Algorithm

To perform LU Decomposition on a matrix:
1. Start: Take your main matrix A.
2. Find U: Use the same steps as Gauss Elimination (Forward Elimination) to create zeros below the diagonal.
   This resulting matrix is your U.
3. Find L: As you create zeros for U, keep track of the "multipliers" you used.
4. Put these multipliers in a new matrix. The diagonal of L will be all 1s.
5. Solve:First, solve Ly = b (Forward Substitution).Then, solve Ux = y (Back Substitution).
6. Stop: The x values are our final answer.

---

## Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

bool decomp(vector<vector<double>>& A,int n,vector<vector<double>>& L,vector<vector<double>>& U,vector<int>& p){
    for(int i=0;i<n;i++){
        p[i]=i;
        for(int j=0;j<n;j++){
            U[i][j]=A[i][j];
            L[i][j]=(i==j?1:0);}}

    for(int k=0;k<n;k++){
        int r=k;
        double v=fabs(U[k][k]);
        for(int i=k+1;i<n;i++){
            if(fabs(U[i][k])>v){
                v=fabs(U[i][k]);
                r=i;}}
        if(v<1e-12) return false;
        if(r!=k){
            swap(U[k],U[r]);
            swap(L[k],L[r]);
            swap(p[k],p[r]);
            for(int j=0;j<k;j++)swap(L[k][j],L[r][j]);}
        for(int i=k+1;i<n;i++){
            L[i][k]=U[i][k]/U[k][k];
            for(int j=k;j<n;j++) U[i][j]-=L[i][k]*U[k][j];}}
    return true;
}

void fwd(const vector<vector<double>>& L,vector<double>& y,const vector<double>& b,const vector<int>& p,int n){
    vector<double> bp(n);
    for(int i=0;i<n;i++){bp[i]=b[p[i]];}
    for(int i=0;i<n;i++){
        y[i]=bp[i];
        for(int j=0;j<i;j++) y[i]-=L[i][j]*y[j];}}

void bwd(const vector<vector<double>>& U,vector<double>& x,const vector<double>& y,int n) {
    for(int i=n-1;i>=0;i--){
        if(fabs(U[i][i])<1e-12){
            x[i]=0;
            continue;}
        x[i]=y[i];
        for(int j=i+1;j<n;j++) x[i]-=U[i][j]*x[j];
        x[i]/=U[i][i];}}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;fin >> n;

    vector<vector<double>> A(n,vector<double>(n)),L(n,vector<double>(n)),U(n,vector<double>(n));
    vector<int> p(n);
    vector<double> b(n),x(n),y(n);

    for(int i=0;i<n;i++)for(int j=0;j<n;j++)fin >> A[i][j];

    for(int i=0;i<n;i++)fin >> b[i];

    bool ok=decomp(A,n,L,U,p);

    if(!ok){
        fout << "NO UNIQUE SOLUTION (Matrix singular)\n";
        return 0;
    }

    bool infinite = false;
    for(int i=0;i<n;i++){
        bool allZero = true;
        for(int j=0;j<n;j++){
            if(fabs(A[i][j])>1e-12){
                allZero = false;
                break;}}
        if(allZero && fabs(b[i])<1e-12)
            infinite = true;
        if(allZero && fabs(b[i])>1e-12){
            fout << "NO SOLUTION\n";
            return 0;
        }
    }

    fwd(L,y,b,p,n);
    bwd(U,x,y,n);

    fout<<fixed<<setprecision(6);

    fout<<"\nL (Lower Triangular):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) fout << setw(12) << L[i][j];
        fout<<"\n";
    }

    fout<<"\nU (Upper Triangular):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) fout<<setw(12)<<U[i][j];
        fout<<"\n";
    }

    fout<<"\nSolution:\n";
    for(int i=0;i<n;i++)
        fout<<"x"<<i+1<<" = "<<x[i]<<"\n";

    if(infinite) fout<<"\nINFINITE SOLUTIONS\n";
    else  fout<<"\nUNIQUE SOLUTION\n";

    return 0;
}
```

## Sample Input:

```cpp
3
1 2 3
2 4 6
7 8 9
1 2 3
```

## Sample Output:

```cpp
NO UNIQUE SOLUTION (Matrix singular)
```

## [Back to Top](#about-this-project)

---
## Matrix Inversion

### Theory
Matrix Inversion is the process of finding a matrix (written as $A^{-1}$) that, when multiplied by the original matrix ($A$), gives you the Identity Matrix ($I$).Think of it like numbers: The "inverse" of $5$ is $\frac{1}{5}$, because $5 \times \frac{1}{5} = 1$. In matrices, it looks like this:$$A \times A^{-1} = I$$The Identity Matrix ($I$) is just a matrix with 1s on the diagonal and 0s everywhere else.

### Algorithm

To perform LU Decomposition on a matrix:
1. Start: Take your main matrix A.
2. Find U: Use the same steps as Gauss Elimination (Forward Elimination) to create zeros below the diagonal.
   This resulting matrix is your U.
3. Find L: As you create zeros for U, keep track of the "multipliers" you used.
4. Put these multipliers in a new matrix. The diagonal of L will be all 1s.
5. Solve:First, solve Ly = b (Forward Substitution).Then, solve Ux = y (Back Substitution).
6. Stop: The x values are our final answer.

---

## Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

bool decomp(vector<vector<double>>& A,int n,vector<vector<double>>& L,vector<vector<double>>& U,vector<int>& p){
    for(int i=0;i<n;i++){
        p[i]=i;
        for(int j=0;j<n;j++){
            U[i][j]=A[i][j];
            L[i][j]=(i==j?1:0);}}

    for(int k=0;k<n;k++){
        int r=k;
        double v=fabs(U[k][k]);
        for(int i=k+1;i<n;i++){
            if(fabs(U[i][k])>v){
                v=fabs(U[i][k]);
                r=i;}}
        if(v<1e-12) return false;
        if(r!=k){
            swap(U[k],U[r]);
            swap(L[k],L[r]);
            swap(p[k],p[r]);
            for(int j=0;j<k;j++)swap(L[k][j],L[r][j]);}
        for(int i=k+1;i<n;i++){
            L[i][k]=U[i][k]/U[k][k];
            for(int j=k;j<n;j++) U[i][j]-=L[i][k]*U[k][j];}}
    return true;
}

void fwd(const vector<vector<double>>& L,vector<double>& y,const vector<double>& b,const vector<int>& p,int n){
    vector<double> bp(n);
    for(int i=0;i<n;i++){bp[i]=b[p[i]];}
    for(int i=0;i<n;i++){
        y[i]=bp[i];
        for(int j=0;j<i;j++) y[i]-=L[i][j]*y[j];}}

void bwd(const vector<vector<double>>& U,vector<double>& x,const vector<double>& y,int n) {
    for(int i=n-1;i>=0;i--){
        if(fabs(U[i][i])<1e-12){
            x[i]=0;
            continue;}
        x[i]=y[i];
        for(int j=i+1;j<n;j++) x[i]-=U[i][j]*x[j];
        x[i]/=U[i][i];}}

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;fin >> n;

    vector<vector<double>> A(n,vector<double>(n)),L(n,vector<double>(n)),U(n,vector<double>(n));
    vector<int> p(n);
    vector<double> b(n),x(n),y(n);

    for(int i=0;i<n;i++)for(int j=0;j<n;j++)fin >> A[i][j];

    for(int i=0;i<n;i++)fin >> b[i];

    bool ok=decomp(A,n,L,U,p);

    if(!ok){
        fout << "NO UNIQUE SOLUTION (Matrix singular)\n";
        return 0;
    }

    bool infinite = false;
    for(int i=0;i<n;i++){
        bool allZero = true;
        for(int j=0;j<n;j++){
            if(fabs(A[i][j])>1e-12){
                allZero = false;
                break;}}
        if(allZero && fabs(b[i])<1e-12)
            infinite = true;
        if(allZero && fabs(b[i])>1e-12){
            fout << "NO SOLUTION\n";
            return 0;
        }
    }

    fwd(L,y,b,p,n);
    bwd(U,x,y,n);

    fout<<fixed<<setprecision(6);

    fout<<"\nL (Lower Triangular):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) fout << setw(12) << L[i][j];
        fout<<"\n";
    }

    fout<<"\nU (Upper Triangular):\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) fout<<setw(12)<<U[i][j];
        fout<<"\n";
    }

    fout<<"\nSolution:\n";
    for(int i=0;i<n;i++)
        fout<<"x"<<i+1<<" = "<<x[i]<<"\n";

    if(infinite) fout<<"\nINFINITE SOLUTIONS\n";
    else  fout<<"\nUNIQUE SOLUTION\n";

    return 0;
}
```

## Sample Input:

```cpp
3
1 2 3
2 4 6
7 8 9
1 2 3
```

## Sample Output:

```cpp
NO UNIQUE SOLUTION (Matrix singular)
```

## [Back to Top](#about-this-project)

---

# Curve Fitting

---

## Linear Regression

### Theory

Linear Regression fits a straight line through a set of data points such that the sum of the squares of the vertical differences between the observed values and the values predicted by the line is minimized. The line can be expressed as:

y = a + b\*x

Where:

x is the independent variable

y is the dependent variable

a is the y-intercept of the line

b is the slope of the line

The process involves two main phases:

Compute sums: Calculate the sums of x, y, x*x, and x*y over all data points.

Calculate coefficients:

b = (n*Σ(x*y) - Σx*Σy) / (n*Σ(x^2) - (Σx)^2)  
a = (Σy / n) - b\*(Σx / n)

Prediction: Once a and b are calculated, the line can predict y for any given x.

### Algorithm / Steps (with Mathematical Expressions)

1. Input the data points x[i] and y[i] for i = 0 to n-1
2. Compute Σx, Σy, Σ(x^2), Σ(xy)
3. Compute the slope b and intercept a using the formulas
4. Construct the linear equation y = a + bx
5. Predict y for any given x using the linear equation

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
5
1 2 3 4 5
2 4 5 4 5
6
```

## Sample Output:

```cpp
a = 2.2
b = 0.6
Linear equation: y = 2.2 + 0.6x
y(6) = 5.8
```

## [Back to Top](#about-this-project)

---

## Exponential Regression

### Theory

Exponential Regression fits data to an exponential model of the form:

Y = A * e^(B*X)

Where:

(X) is the independent variable

(Y) is the dependent variable

A and B are constants

The process involves two main phases:

Linearization: Take the natural logarithm of Y to transform the equation into a linear form:

ln(Y) = ln(A) + B\*X

Apply Linear Regression: Use least squares on the transformed data to calculate ln(A) and B.

Prediction: Once A and B are known, the model can predict Y for any X.

### Algorithm / Steps (with Mathematical Expressions)

1. Read the data points (X[i], Y[i]), i = 1....n

2. Compute ln(Y[i]) for all i

3. Compute sums  
   ΣX, Σln(Y), ΣX\*ln(Y), ΣX²

4. Solve for coefficients  
   B = (nΣ(X\*ln(Y)) - ΣXΣln(Y)) / (nΣX² - (ΣX)²),  
   ln(A) = (Σln(Y) - BΣX) / n,  
   A = e^(ln(A))

5. Obtain the solution and display the regression equation: Y = A * e^(B*X)

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
5
1 2 3 4 5
2 4 5 4 5
```

## Sample Output:

```cpp
11.2584 20 48.0728 28.4202
y = 1.771 + 0.990 e^(z/4)
y(6) = 6.208
```

## [Back to Top](#about-this-project)

---

## Polynomial Regression

### Theory

Polynomial Regression fits a polynomial of degree n to a set of data points using the least squares method. The polynomial can be represented as:

Y = a0 + a1X + a2X² + ... + an\*X^n

Where:

(X) is the independent variable

(Y) is the dependent variable

a0, a1, ..., an are coefficients

The process involves two main phases:

Construct normal equations: Using least squares, form n+1 equations based on the sum of powers of X and products with Y.

Solve for coefficients: Solve the system of linear equations to find a0, a1, ..., an.

Prediction: Use the polynomial to predict Y for any X.

### Algorithm / Steps (with Mathematical Expressions)

1. Read the data points (X[i], Y[i]), i = 1....n

2. Compute ΣX^k and Σ(X^k \* Y) for k = 0 to 2n

3. Set up equations ΣY = a0ΣX^0 + a1ΣX^1 + ... + an\*ΣX^n and so on

4. Solve the linear system using methods like Gauss Elimination

5. Display the polynomial regression equation: Y = a0 + a1X + a2X² + ... + an\*X^n

---

## Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;

    int deg;
    fin >> deg;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
        fin >> x[i];

    for (int i = 0; i < n; i++)
        fin >> y[i];

    vector<double> sumPow(2 * deg + 1, 0);
    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= 2 * deg; j++)
        {
            sumPow[j] += xi;
            xi *= x[i];
        }
    }

    vector<double> sumXY(deg + 1, 0);
    for (int i = 0; i < n; i++)
    {
        double xi = 1;
        for (int j = 0; j <= deg; j++)
        {
            sumXY[j] += xi * y[i];
            xi *= x[i];
        }
    }

    vector<vector<double>> matt(deg + 1, vector<double>(deg + 2, 0));
    for (int i = 0; i <= deg; i++)
    {
        for (int j = 0; j <= deg; j++)
        {
            matt[i][j] = sumPow[i + j];
        }
        matt[i][deg + 1] = sumXY[i];
    }

    for (int i = 0; i <= deg; i++)
    {
        for (int j = i + 1; j <= deg; j++)
        {
            if (abs(matt[j][i]) > abs(matt[i][i]))
                swap(matt[i], matt[j]);
        }
        for (int j = i + 1; j <= deg; j++)
        {
            double rt = matt[j][i] / matt[i][i];
            for (int k = i; k <= deg + 1; k++)
            {
                matt[j][k] -= rt * matt[i][k];
            }
        }
    }

    vector<double> a(deg + 1, 0);
    for (int i = deg; i >= 0; i--)
    {
        a[i] = matt[i][deg + 1];
        for (int j = i + 1; j <= deg; j++)
        {
            a[i] -= matt[i][j] * a[j];
        }
        a[i] /= matt[i][i];
    }

    for (int i = 0; i <= deg; i++)
    {
        fout << "a" << i << " = " << a[i] << '\n';
    }

    // Predict
    double val;
    fin >> val;

    double ypred = 0;
    for (int i = 0; i <= deg; i++)
    {
        ypred += a[i] * pow(val, i);
    }

    fout << "y(" << val << ") = " << ypred << '\n';

    fin.close();
    fout.close();

    return 0;
}
```

## Sample Input:

```cpp
5
2
1 2 3 4 5
2 4 5 4 5
6
```

## Sample Output:

```cpp
a0 = 0.2
a1 = 2.31429
a2 = -0.285714
y(6) = 3.8
```

## [Back to Top](#about-this-project)

---

# Numerical Differentiation

---

## Newton's Forward Difference

### Theory

Newton's Forward Difference Formula approximates the derivative of a function given tabulated data points. It is used when the point of interest is near the beginning of the dataset and the x values are equally spaced.

Let x0, x1, ..., xn be the x values with step size h. Let x be the point of interest and u = (x - x0)/h.

First derivative:

f'(x) = (1/h) [ Δy0 + ((2u - 1)/2) Δ²y0 + ((3u² - 6u + 2)/6) \* Δ³y0 + ... ]

Second derivative:

f''(x) = (1/h²) [ Δ²y0 + (u - 1) Δ³y0 + ... ]

### Algorithm / Steps (with Mathematical Expressions)

1. Input n, x[], y[], and target x
2. Construct forward difference table
3. Compute h = x[1] - x[0], u = (x - x0)/h
4. Apply formulas to calculate f'(x) and f''(x)
5. Output difference table and derivatives

---

## Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

double factorial(int n)
{
    double f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cout << "Num of data points:\n";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (double &v : x) cin >> v;

    cout << "Enter y values:\n";
    for (double &v : y) cin >> v;

    double xp;
    cout << "Enter the targeted value:\n";
    cin >> xp;

    vector<vector<double>> d(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        d[i][0] = y[i];

    for (int col = 1; col < n; col++)
        for (int row = 0; row < n - col; row++)
            d[row][col] = d[row + 1][col - 1] - d[row][col - 1];

    cout << "Forward difference table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << setw(8) << d[i][j] << " ";
        cout << '\n';
    }

    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;

    double firstDer =
        d[0][1]
        + (2 * u - 1) * d[0][2] / factorial(2)
        + (3 * u * u - 6 * u + 2) * d[0][3] / factorial(3);

    firstDer /= h;

    double secondDer =
        d[0][2]
        + (u - 1) * d[0][3];

    secondDer /= (h * h);

    cout << "f'(x) = " << firstDer << '\n';
    cout << "f''(x) = " << secondDer << '\n';

    return 0;
}

```

## Sample Input:

```cpp
5
1 2 3 4 5
1 8 27 64 125
2
```

## Sample Output:

```cpp
Num of data points:
Enter x values:
Enter y values:
Enter the targeted value:
Forward difference table:
       1        7       12        6        0
       8       19       18        6
      27       37       24
      64       61
     125
f'(x) = 12
f''(x) = 12
```

## [Back to Top](#about-this-project)

---

## Newton's Backward Difference

### Theory

Newton's Backward Difference Formula approximates the derivative of a function when the point of interest is near the end of the dataset and the x values are equally spaced.

Let x0, x1, ..., xn be the x values with step size h. Let x be the point of interest and u = (x - xn)/h.

First derivative:

f'(x) = (1/h) [ ∇yn + ((2u + 1)/2) ∇²yn + ((3u² + 6u + 2)/6) \* ∇³yn + ... ]

Second derivative:

f''(x) = (1/h²) [ ∇²yn + (u + 1) ∇³yn + ... ]

### Algorithm / Steps (with Mathematical Expressions)

1. Input n, x[], y[], and target x
2. Construct backward difference table
3. Compute h = x[1] - x[0], u = (x - xn)/h
4. Apply formulas to calculate f'(x) and f''(x)
5. Output difference table and derivatives

---

## Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

double factorial(int n)
{
    double f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cout << "Num of data points:\n";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    double xp;
    cout << "Enter the targeted value:\n";
    cin >> xp;

    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
        for (int i = n - 1; i >= j; i--)
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];

    cout << "Backward difference table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(8) << diff[i][j] << " ";
        cout << '\n';
    }

    double h = x[1] - x[0];
    double u = (xp - x[n - 1]) / h;

    double firstDer =
        diff[n - 1][1]
        + (2 * u + 1) * diff[n - 1][2] / factorial(2)
        + (3 * u * u + 6 * u + 2) * diff[n - 1][3] / factorial(3);

    firstDer /= h;

    double secondDer =
        diff[n - 1][2]
        + (u + 1) * diff[n - 1][3];

    secondDer /= (h * h);

    cout << "f'(x) = " << firstDer << '\n';
    cout << "f''(x) = " << secondDer << '\n';

    return 0;
}

```

## Sample Input:

```cpp
5
1 2 3 4 5
1 8 27 64 125
4
```

## Sample Output:

```cpp
Num of data points:
Enter x values:
Enter y values:
Enter the targeted value:
Backward difference table:
       1
       8        7
      27       19       12
      64       37       18        6
     125       61       24        6        0
f'(x) = 48
f''(x) = 24
```

## [Back to Top](#about-this-project)

---

# Numerical Integration

---

## Simpson's One-Third Rule

### Theory

Simpson’s 1/3 Rule is a numerical integration method used to approximate the definite integral of a function. The integral of f(x) from a to b is approximated as:

Integral = (h/3) [ (y0 + yn) + 4(y1 + y3 + y5 + ...) + 2(y2 + y4 + y6 + ...) ]

Where:

y0, y1, ..., yn are the values of the function at equally spaced points

h = (b - a) / n, and n must be even

The process involves dividing the interval [a, b] into n equal subintervals. The integral is then computed by taking the weighted sum of the function values according to the formula above. This method combines parabolic approximations over pairs of intervals to provide higher accuracy than the trapezoidal rule.

### Algorithm / Steps (with Mathematical Expressions)

1. Input the function values and limits
2. Compute step size h = (b - a) / n
3. Compute the weighted sum according to the formula
4. Obtain the approximate value of the integral

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
0 1 4
```

## Sample Output:

```cpp
Lower limit a: 0
Upper limit b: 1
Number of intervals: 4
Step size h: 0.25

Integration of the function: 0.78539
```

## [Back to Top](#about-this-project)

---

## Simpson's Three-Eighths Rule

### Theory

Simpson’s 3/8 Rule is a numerical integration method that approximates the integral of a function over an interval by fitting cubic polynomials through sets of four points. The integral of f(x) from a to b is approximated as:

Integral = (3h/8) [ (y0 + yn) + 3(y1 + y2 + y4 + y5 + ...) + 2(y3 + y6 + ...) ]

Where:

y0, y1, ..., yn are the values of the function at equally spaced points

h = (b - a) / n, and n must be a multiple of 3

The interval [a, b] is divided into n equal subintervals. The integral is computed by taking a weighted sum of function values, where multiples of 3 are multiplied by 2 and the remaining intermediate points are multiplied by 3. This method gives higher accuracy for functions that are not well-approximated by parabolas.

### Algorithm / Steps (with Mathematical Expressions)

1. Input the function values and limits
2. Compute step size h = (b - a) / n
3. Compute the weighted sum according to the formula
4. Obtain the approximate value of the integral

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
0 4.5 9
```

## Sample Output:

```cpp
Lower limit a: 0
Upper limit b: 4.5
Number of intervals: 9
Step size h: 0.5

Integration of the function: 6.329
```

## [Back to Top](#about-this-project)

---

# Solution of Differential Equations

---

## Runge-Kutta method

### Theory

The 4th Order Runge-Kutta (RK4) method solves ODEs of the form dy/dx = f(x, y), y(x0) = y0. The next value yn+1 is approximated using:

h = step size  
k1 = h _ f(xn, yn)  
k2 = h _ f(xn + h/2, yn + k1/2)  
k3 = h _ f(xn + h/2, yn + k2/2)  
k4 = h _ f(xn + h, yn + k3)  
yn+1 = yn + (1/6)*(k1 + 2*k2 + 2\*k3 + k4)  
xn+1 = xn + h

Compute k1, k2, k3, k4, then yn+1. Repeat until x = xn. This gives an accurate approximation of y at each step.

### Algorithm / Steps (with Mathematical Expressions)

1. Input the initial values x0, y0, the final value xn, and step size h
2. Compute k1, k2, k3, k4 using the formulas above
3. Compute yn+1 = yn + (1/6)*(k1 + 2*k2 + 2\*k3 + k4)
4. Update xn+1 = xn + h
5. Repeat the process until x = xn
6. Obtain the approximate solution for y at each step

---

## Code:

```cpp
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
```

## Sample Input:

```cpp
0 1
0.2
0.1
```

## Sample Output:

```cpp
f(0.2) = 1.24
```

## [Back to Top](#about-this-project)

---
