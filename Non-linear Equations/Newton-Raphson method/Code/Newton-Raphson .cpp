#include <bits/stdc++.h>

using namespace std;

double func(double x, double a, double b, double c, double d) {
    return a*x*x*x + b*x*x + c*x + d;
}

int main() {
    double a,b,c,d,x1,x2,e,midpoint,func_at_mid,func_at_x1,func_at_x2;
    int max_iterations, iteration_cnt = 0;

    ifstream input_file("input.txt");ofstream output_file("output.txt");

    if (!input_file.is_open()) {
        cerr << "Error opening input file!"<<"\n";
        return -1;}

    input_file>>a>>b>>c>>d;
    input_file>>x1>>x2>>e>>max_iterations;

    func_at_x1 = func(x1,a,b,c,d);
    func_at_x2 = func(x2,a,b,c,d);

    if (func_at_x1*func_at_x2 >0) {
        output_file<<"No root found in the interval ["<<x1<< ", "<<x2<<"]"<<"\n";
        return -1;
    }

    output_file << "Searching for the root in the interval ["<<x1<<", "<<x2<<"]"<<"\n";

    while ((x2-x1)/2.0>e && iteration_cnt<max_iterations){
        midpoint=(x1+x2)/2.0;
        func_at_mid = func(midpoint,a,b,c,d);

        output_file << "Iteration "<<iteration_cnt+1<<": Midpoint = "<<midpoint<<", f(midpoint) = "<<func_at_mid<<"\n";

        if (func_at_mid==0.0){break;}
        if (func_at_x1*func_at_mid<0){
            x2 = midpoint;
            func_at_x2=func_at_mid;
        } else {x1=midpoint;
            func_at_x1=func_at_mid;}
            iteration_cnt++;
    }

    if (iteration_cnt == max_iterations) {
        output_file<<"Maximum iterations reached. Approximate root is "<<midpoint<<"\n";
    } else {
        output_file<<"The root is approximately="<<midpoint<<" with f(midpoint) = "<< func(midpoint,a,b,c,d)<<"\n";
    }
    input_file.close();output_file.close();
    return 0;
}
