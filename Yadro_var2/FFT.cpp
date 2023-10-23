#include "FFT.h"

FFT::FFT(vector<double> x)
{
    this->x = this->transform(x);
}
FFT::FFT(vector<ftype> x)
{
    this->x = x;
}
FFT::~FFT()
{
}

vector<ftype> FFT::transform(vector<double>& a)
{
    vector<ftype> b;
    for (double a_i : a) {
        b.push_back((ftype)a_i);
    }
    return b;
}

vector<ftype> FFT::DFT_slow() {
    int N = x.size();

    for (int k = 0; k < N; k++) {
        vector<ftype> new_line;
        for (int n = 0; n < N; n++) {


            ftype M_i_j = exp(-2. * 1i * pi * (double)k * (double)n / (double)N);
            new_line.push_back(M_i_j);
        }
        this->M.push_back(new_line);
    }
    return this->scalar(this->M, this->x);

}
vector<ftype> FFT::slice(vector<ftype>& vec, int start, int finish, int step) {
    vector<ftype> res;
    for (int i = start; i < finish; i += step) {
        res.push_back(vec[i]);
    }
    return res;
}
vector<ftype> FFT::FFT_fast(vector<ftype>& x) {
    int N = x.size();
    if (N % 2 != 0) {
        return vector<ftype>();
    }
    else if (N <= 1) {
        return this->DFT_slow();
    }
    else {
        vector<ftype> X_even = this->slice(x, 0, this->x.size(), 2);
        vector<ftype> X_odd = this->slice(x, 1, this->x.size(), 2);

        vector<ftype> factor;
        for (int i = 0; i < N; i++) {
            factor.push_back(exp(-2. * 1i * pi * (double)i / (double)N));
        }
        vector<ftype> first_slice = this->slice(factor, N / 2, N, 1);
        vector<ftype> first_scal = this->scal(first_slice, X_odd);
        vector<ftype> first = this->summa(X_even, first_scal);
        vector<ftype> second_slice = this->slice(factor, 0, N / 2, 1);
        vector<ftype> second_scal = this->scal(second_slice, X_odd);
        vector<ftype> second = this->summa(X_even, second_scal);
        first.insert(first.end(), second.begin(), second.end());
        this->straight = first;
        return first;

    }
    //return x;
}

vector<ftype> FFT::summa(vector<ftype>& A, vector<ftype>& B) {

    vector<ftype> res;
    for (int i = 0; i < A.size(); i++) {
        res.push_back(A[i] + B[i]);
    }
    return res;

}
vector<ftype> FFT::FFT_reverse()
{
    int N = straight.size();
    if (N % 2 != 0) {
        return vector<ftype>();
    }
    
    else {
        vector<ftype> X_even = this->slice(straight, 0, this->straight.size(), 2);
        vector<ftype> X_odd = this->slice(straight, 1, this->straight.size(), 2);

        vector<ftype> factor;
        for (int i = 0; i < N; i++) {
            factor.push_back(exp(2. * 1i * pi * (double)i / (double)N));
        }
        vector<ftype> first_slice = this->slice(factor, N / 2, N, 1);
        vector<ftype> first_scal = this->scal(first_slice, X_odd);
        vector<ftype> first = this->summa(X_even, first_scal);
        vector<ftype> second_slice = this->slice(factor, 0, N / 2, 1);
        vector<ftype> second_scal = this->scal(second_slice, X_odd);
        vector<ftype> second = this->summa(X_even, second_scal);
        first.insert(first.end(), second.begin(), second.end());
        //this->straight = first;
        return first;

    }
    return vector<ftype>();
}
vector<ftype> FFT::concatenate(const vector<ftype> A, vector<ftype> B) {

    vector<ftype> res;
    for (int i = 0; i < A.size(); i++) {
        res.push_back(A[i]);
    }
    for (int i = 0; i < B.size(); i++) {
        res.push_back(B[i]);
    }
    return res;

}

vector<ftype> FFT::scalar(vector<vector<ftype>>& M, vector<ftype>& x) {

    int M_size = M.size();
    int x_size = x.size();
    vector<ftype> res;
    for (int i = 0; i < x_size; i++) {
        ftype res_i(0, 0);
        for (int j = 0; j < x_size; j++) {
            res_i += M[i][j] * x[j];
        }
        res.push_back(res_i);
    }
    return res;
}


vector<ftype> FFT::scal(vector<ftype>& M, vector<ftype>& x) {

    int M_size = M.size();
    int x_size = x.size();
    vector<ftype> res;
    for (int i = 0; i < x_size; i++) {


        res.push_back(M[i] * x[i]);


    }
    return res;
}


void FFT::print(vector<ftype> r) {
    for (ftype i : r) {
        cout << i << endl;
    }
}

vector<ftype> FFT::get_x() {
    return this->x;
}
