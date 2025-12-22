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

### 1. [Linear Equations] (#linear equations)
- **Gauss Elimination**
  - Theory
  - Code
  - Input
  - Output

- **Gauss Jordan Elimination**
  - Theory
  - Code
  - Input
  - Output

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
## Gauss–Jordan Method

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
   a[k][j] = a[k][j] - a[k][i] * a[i][j]

5. **Repeat for all rows**  
   Continue steps 2 to 4 for i = 1.... n  until the matrix becomes:
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
---




