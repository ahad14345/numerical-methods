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

### 1. Linear Equations
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
### 4. Numerical Differentiation
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
### 5. Numerical Integration
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
### 6. Ordinary Differential Equations

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

\[
AX = B
\]

Where:
- \(A\) is the coefficient matrix  
- \(X\) is the matrix of unknown variables  
- \(B\) is the constant matrix  

The augmented matrix form is:

\[
[A|B] =
\begin{bmatrix}
a_{11} & a_{12} & \dots & a_{1n} & | & b_1 \\
a_{21} & a_{22} & \dots & a_{2n} & | & b_2 \\
\vdots & \vdots &       & \vdots & | & \vdots \\
a_{n1} & a_{n2} & \dots & a_{nn} & | & b_n
\end{bmatrix}
\]

The goal of the Gauss–Jordan method is to convert this matrix into **reduced row-echelon form**, where:

- The diagonal elements become **1**
- All other elements in each pivot column become **0**
- Each row represents one variable clearly

After this transformation, the solution is obtained directly from the last column of the matrix.

---

### Algorithm / Steps (with Mathematical Expressions)

1. **Input the matrix**  
   Read the augmented matrix into a 2D array  
   \[
   a[i][j], \quad i = 1 \dots n,\; j = 1 \dots n+1
   \]

2. **Select the pivot element**  
   For each row \(i\), choose the diagonal element:
   \[
   pivot = a[i][i]
   \]

3. **Make the pivot equal to 1**  
   Divide the entire row by the pivot element:
   \[
   a[i][j] = \frac{a[i][j]}{pivot}, \quad \forall j
   \]

4. **Make other elements of the column zero**  
   For all rows \(k \ne i\):
   \[
   a[k][j] = a[k][j] - a[k][i] \times a[i][j]
   \]

5. **Repeat for all rows**  
   Continue steps 2 to 4 for \(i = 1 \dots n\) until the matrix becomes:
   \[
   [I|X]
   \]
   where \(I\) is the identity matrix.

6. **Obtain the solution**  
   The values of the variables are:
   \[
   x_i = a[i][n+1]
   \]

---




