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
