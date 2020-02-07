#include <iostream>
#include <cmath>
using namespace std;

void stat(const double [], int, double []);

int main()
{
    double A[] = {1.2,-3.5,6.9,7.8,12.5,-0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[4];
    stat(A,N,B);
    cout << "Average = " << B[0];
    cout << "\nS.D. = " << B[1];
    cout << "\nMax = " << B[2];
    cout << "\nMin = " << B[3];
    return 0;
}

//Write definition of stat() here 
void stat(const double dataIn[], int n, double dataOut[]) {
    // average process
    dataOut[0] = 0;
    for (short i = 0; i < n; i++) {
        dataOut[0] += dataIn[i];
    }
    dataOut[0] = dataOut[0] / n;
    
    // S.D. process
    double sumPow = 0;
    for (short i = 0; i < n; i++) {
        sumPow += pow(dataIn[i] - dataOut[0], 2);
    }
    
    dataOut[1] = pow(sumPow / n, 0.5);
    
    // max process
    dataOut[2] = dataIn[0];
    for (short i = 0; i < n; i++) {
        if (dataOut[2] < dataIn[i]) {
            dataOut[2] = dataIn[i];
        }
    }
    
    // min process
    dataOut[3] = dataIn[0];
    for (short i = 0; i < n; i++) {
        if (dataOut[3] > dataIn[i]) {
            dataOut[3] = dataIn[i];
        }
    }
}
