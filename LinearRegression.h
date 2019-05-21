#ifndef LINEARREGRESION_H
#define LINEARREGRESION_H   
#include <iostream>
#include <vector>

using namespace std;

class LinearRegression {

    public:
        LinearRegression() {}
        LinearRegression( vector<double> &, vector<double> & );
        ~LinearRegression() {}

        void trainAlgorithm( double, double );
        double hypothesis( double );

    private:
        vector<double> x_value;
        vector<double> y_value;
        double m_elems;
        double theta0;
        double theta1;
        double error0;
        double error1;
        static int proof;

        bool isConverged();
};

int LinearRegression::proof = 1;

LinearRegression::LinearRegression( vector<double> &x_value, vector<double> &y_value ) {
    this -> x_value = x_value;
    this -> y_value = y_value;
    this -> m_elems = x_value.size();
}

void LinearRegression::trainAlgorithm( double theta0_init, double theta1_init ) {
    theta0 = theta0_init;
    theta1 = theta1_init;

    while( isConverged() ) {
        double step = 0.01;
        double theta0_grad = 0;
        double theta1_grad = 0;

        for( int i = 0; i < m_elems; ++i ) 
            theta0_grad += (( theta0 + theta1 * x_value[ i ]) - y_value[ i ]);
        theta0_grad /= m_elems;

        for( int i = 0; i < m_elems; ++i ) 
            theta1_grad += (( theta0 + theta1 * x_value[ i ]) - y_value[ i ]) * x_value[ i ];
        theta1_grad /= m_elems;

        cout << "theta0: \t" << theta0 << ", theta1: \t" << theta1 << "\r\n";
        cout << "theta0_grad: \t" << theta0_grad << ", theta1_grad: \t" << theta1_grad << "\r\n";
        cout << endl;
        theta0 = theta0 - ( step * theta0_grad );
        theta1 = theta1 - ( step * theta1_grad );
        ++proof;

    }
}

double LinearRegression::hypothesis( double x ) {
    return theta0 + theta1 * x;
}

bool LinearRegression::isConverged() {
    for( int i = 0; i < m_elems; ++i )
        error0 += (( theta0 + theta1 * x_value[ i ]) - y_value[ i ]);
    error0 /= m_elems;

    for( int i = 0; i < m_elems; ++i )
        error1 += (( theta0 + theta1 * x_value[ i ]) - y_value[ i ]) * x_value[ i ];
    error1 /= m_elems;

    if( abs( error0 ) > 0.00005 && abs( error1 ) > 0.00005 ) {
        cout << "#TEST: " << proof << endl;
        cout << "Error0: \t" << error0 << ", Error1: \t" << error1 << endl;
        return true;
    }
    else
        return false;
       
}

    
#endif