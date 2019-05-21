#include "Matrix.h"
using namespace std;

int main() {

    cout << "MATRIX A" << endl;
    Matrix <int> A( 1, 2 );
    A.fillMatrix();
    cout << endl;

    cout << "MATRIX B" << endl;
    Matrix <int> B( 1, 2 );
    B.fillMatrix();
    cout << endl;

    cout << "MATRIX RESULTANTE" << endl;
    cout << A - B << endl;
    
    return 0;
}