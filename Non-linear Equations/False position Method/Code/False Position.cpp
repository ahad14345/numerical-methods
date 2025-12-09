#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x, double a, double b, double c, double d) {
    return a*x*x*x + b*x*x + c*x + d;
}

int main() {
    double a,b,c,d,e,xl,xu,xr;
    int cnt;

    ifstream in_file("input.txt");
    ofstream out_file("output.txt");

    if(!in_file.is_open()){
        cerr<< "Error opening input file!"<<"\n";
        return -1;}

    in_file>>a>>b>>c>>d;
    in_file>>xl>>xu>>e>>cnt;
    in_file.close();

    xr=xl;
    double fxl =f(xl,a,b,c,d), fxu = f(xu,a,b,c,d),fxr;

    if(fxl*fxu>0) {
        out_file<<"No root found in the interval [" <<xl<<", "<<xu<< "]"<<"\n";
        out_file.close();
        return 0;}
    out_file<<"Searching for the root in the interval [" <<xl<<", "<<xu<< "]\n";
    int iter = 1;
    while (iter<=cnt){
        xr = ((xl*fxu)-(xu*fxl))/(fxu-fxl);
        fxr = f(xr,a,b,c,d);

        out_file<<"Iteration "<<iter<<": x = " << xr << ", f(x) = "<<fxr<<"\n";

        if (fabs(fxr)<e){break;}

        if (fxl*fxr<0){
            xu = xr;
            fxu = fxr;
        }else{
            xl = xr;
            fxl = fxr;}
        iter++;
    }
    out_file<<"\nThe root is approximately: "<<xr<<" with f(x) = "<<fxr<< "\n";
    out_file.close();

    return 0;
}
