#include <bits/stdc++.h>
using namespace std;

double f(double x,const vector<double>& coeffs)
{
    double rslt = 0;
    int n = coeffs.size()-1;
    for(int i = 0;i <= n;i++)
        {
            result += coeffs[i]*pow(x, n-i);
        }
    return result;
}

/* double deriv(double x,const vector<double>& coeffs){
    double rslt=0;
    int n=coeffs.size()-1;
    for(int i=0;i<n;i++){rslt+=coeffs[i]*(n-i)*pow(x,n-i-1);}
    return rslt;
} */

void printeqn(const vector<double>& coeffs,ofstream& outFile) 
{
    int n=coeffs.size()-1;
    bool flg=true;
    for(int i=0;i<=n;i++)
    {
        if(coeffs[i]!=0)
        {
            if (!flg)
            {
                outFile << (coeffs[i] > 0 ? " + " : " - ");
            }
            flg = false;
            if(i == n)
            {
                outFile<<abs(coeffs[i]);
            }
            else if(i == n-1)
            {
                outFile << abs(coeffs[i]) << "x";
            }
            else
            {
                outFile << abs(coeffs[i]) << "x^" << n-i;
            }
        }
    }
    outFile << " = 0" << '\n';
}

void printderiv(const vector<double>& coeffs, ofstream& outFile) 
{
    int n = coeffs.size() - 1;
    bool flg = true;
    for(int i=0;i<n;i++)
    {
        if(coeffs[i] !=0)
        {
            if (!flg)
            {
                outFile<<(coeffs[i]*(n-i)>0 ? "+":"-");
            }
            flg = false;
            if(i== n - 1)
            {
                outFile<<abs(coeffs[i]*(n-i));
            }
            else if(i == n - 2)
            {
                outFile<<abs(coeffs[i]*(n-i))<<"x";
            }
            else
            {
                outFile<<abs(coeffs[i]*(n-i))<<"x^"<<n-i-1;
            }
        }
    }
    outFile<<"\n";
}

double secant(double x0, double x1, double e,int maxiter,const vector<double>& coeffs, ofstream& outFile)
{ double f0 = f(x0,coeffs),f1 = f(x1,coeffs);

    for(int iter=1;iter<=maxiter;iter++)
    {if(fabs(f1-f0)< 1e-12)
        {outFile<<"Denominator became zero. Stopping.\n";
            return x1;}
        double x2 =x1- f1*((x1-x0)/(f1-f0)),f2=f(x2,coeffs);
        outFile<<"Iteration "<<iter<<": x = "<<fixed<<setprecision(6)<<x2<<", f(x) = "<<f2<<"\n";

        if(fabs(x2-x1)<e)
            return x2;

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
    }
    return x1;
}


int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile)
    {
        cerr<<"Error opening input file!"<<"\n";
        return -1;
    }

    int degree;
    inFile >> degree;

    vector<double> coeffs(degree + 1);
    for(int i=0;i<=degree;i++)
    {
        inFile >> coeffs[i];
    }

    outFile<<"The equation is: ";
    printeq(coeffs, outFile);
    outFile<<"The derivative is: ";
    printderiv(coeffs, outFile);
    double x0, e;
    int maxiter;
    inFile>>x0>>e>>maxiter;
    double x1 = x0 + 0.5;// bg fr nw u doing it hardcoded in future u can take here x1 frm user it means x0 x1 both user input
    double root = secant(x0,x1,e,maxiter,coeffs,outFile);
    outFile<<"\nThe root is: "<<setprecision(6)<<root<<"\n";

    inFile.close();
    outFile.close();
    return 0;
}
