#include "FFT.h"
#include <random>

vector<ftype> create_double_vector(int n) {
    mt19937 gen(1701);
    cauchy_distribution<> distr(-0000., 1000.);
    vector<ftype> res;
    for (int i = 0; i < n; i++) {
        res.push_back(ftype(distr(gen), distr(gen)) );

    }
    return res;
}

double mistake(vector<ftype> x, vector<ftype> x_change) {
    int N = x.size();
    double res = 0;
    for (int i = 0; i < N; i++) {
        double mist = abs(x[i].real() - x_change[i].real());
        //if (mist < 100) {
        //    cout << "Good!!!" << endl;
        //}
        res += mist;
        
    }
    res /= N;
    return res;

}

int main(int argc, char** argv)
{
    int n = 1000;
    if(argc >= 2)
        n = atoi(argv[1]);
    vector<ftype> x = create_double_vector(n);
    FFT* solver = new FFT(x);
    vector<ftype> res = solver->DFT_slow();
    vector<ftype> res2 = solver->FFT_fast(x);
    vector<ftype> res3 = solver->FFT_reverse();
    cout << "----------\nDFT:\n" << endl;
    solver->print(res);
    cout << "----------\nFFT:\n" << endl;
    solver->print(res2);
    cout << "----------\nFFT reverse:\n" << endl;
    solver->print(res3);
    cout << "----------" << endl;
    cout << "----------" << endl;
    solver->print(solver->get_x());
    cout << "----------" << endl;
    cout << "----------" << endl;
    cout << "Mistake for DFT:" << mistake(solver->get_x(), res) << endl;
    cout << "----------" << endl;
    cout << "----------" << endl;
    cout << "Mistake for FFT:" << mistake(solver->get_x(), res2) << endl;
    cout << "----------" << endl;
    cout << "----------" << endl;
    cout << "Mistake for reverse FFT:" << mistake(solver->get_x(), res3) << endl;





}

