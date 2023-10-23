#pragma once

#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
const double pi = acos(-1);
using namespace std;
typedef complex<double> ftype;
class FFT
{
private:
    vector<ftype> res;
    vector<vector<ftype>> M;
    vector<ftype> x;
    vector<ftype> straight;
public:
    FFT(vector<double> x);
    FFT(vector<ftype> x);

    vector<ftype> DFT_slow();
    vector<ftype> FFT_fast(vector<ftype>&);
    vector<ftype> transform(vector<double>& a);
    vector<ftype> scalar(vector<vector<ftype>>&, vector<ftype>&);
    vector<ftype> scal(vector<ftype>& M, vector<ftype>& x);
    vector<ftype> slice(vector<ftype>& vec, int start, int finish, int step);
    vector<ftype> summa(vector<ftype>&, vector<ftype>&);
    vector<ftype> FFT_reverse();
    vector<ftype> concatenate(const vector<ftype>, vector<ftype>);
    void print(vector<ftype>);
    vector<ftype> get_x();
    
    ~FFT();
};



