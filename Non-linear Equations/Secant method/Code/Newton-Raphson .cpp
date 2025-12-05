#include <bits/stdc++.h>
using namespace std;

double f(double x,const vector<double>& coeffs){
    double rslt=0;
    int n=coeffs.size()-1;
    for(int i=0;i<=n;i++){rslt +=coeffs[i]*pow(x,n-i);}
    return rslt;}

double deriv(double x,const vector<double>& coeffs){
    double rslt=0;
    int n=coeffs.size()-1;
    for(int i=0;i<n;i++){rslt+=coeffs[i]*(n-i)*pow(x,n-i-1);}
    return rslt;
}

void printeq(const vector<double>& coeffs,ofstream& outFile) {
    int n=coeffs.size()-1;
    bool flg=true;
for(int i=0;i<=n;i++){if(coeffs[i]!=0){
            if (!flg){outFile<<(coeffs[i] > 0 ? " + " : " - ");}
            flg = false;
            if(i==n){outFile<<abs(coeffs[i]);
            }else if(i== n-1){
                outFile<<abs(coeffs[i])<<"x";
            }else{
                outFile<<abs(coeffs[i])<<"x^"<<n-i;}}}
                outFile<<" = 0"<<"\n";}

void printderiv(const vector<double>& coeffs, ofstream& outFile) {
    int n =coeffs.size()-1;
    bool flg = true;
for(int i=0;i<n;i++){if(coeffs[i] !=0){
            if (!flg){outFile<<(coeffs[i]*(n-i)>0 ? "+":"-");}
            flg = false;

            if(i== n-1){
                outFile<<abs(coeffs[i]*(n-i));
            }else if(i == n-2){
                outFile<<abs(coeffs[i]*(n-i))<<"x";
            }else{outFile<<abs(coeffs[i]*(n-i))<<"x^"<<n-i-1;}}}
    outFile<<"\n";}

double newtonraphson(double x,double e,int maxiter,const vector<double>& coeffs,ofstream& outFile)
{
    int iter=0;
    while(iter<maxiter)
    {
        double fx =f(x,coeffs),dfx =deriv(x,coeffs);

        if (dfx==0){
            outFile<<"Derivative became zero. Stopping."<<"\n";
            break;}

        double h = fx/dfx,new_x =x-h;

        outFile<<"Iteration "<<(iter+1)<<": x = "<<fixed<<setprecision(6)<<new_x<<", f(x) = "<<fx<<"\n";
        if(abs(new_x-x)<e){return new_x;}
        x =new_x;
        iter++;}

    return x;
}


int main(){
    ifstream inFile("input.txt");ofstream outFile("output.txt");

    if (!inFile){
        cerr <<"Error opening input file!" << "\n";
        return -1;}

        int degree;inFile>>degree;

    vector<double> coeffs(degree + 1);
    for(int i=0;i<=degree;i++){inFile>>coeffs[i];}

    outFile << "The equation is: ";
    printeq(coeffs, outFile);
    outFile << "The derivative is: ";
    printderiv(coeffs, outFile);
    double guess,e;
    int maxiter;
    inFile >> guess >> e >> maxiter;
    double root = newtonraphson(guess,e,maxiter,coeffs,outFile);
    outFile<<"\nThe root is: "<<setprecision(6)<<root<<"\n";
    inFile.close();
    outFile.close();
    return 0;
}
