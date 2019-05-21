#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template < typename Type >
class Matrix { 

    public:
        Matrix();
        Matrix( const int, const int );
        Matrix( const Matrix & );

        ~Matrix();

        void fillMatrix();
        Matrix<Type> operator+( const Matrix & );
        Matrix<Type> operator-( const Matrix & );
        Matrix<Type> operator*( const Matrix & );

        template < typename T >
        friend ostream& operator <<( ostream &, const Matrix <T> );
 
    private:
        int row, col;
        Type **matrix;

};

template < typename Type >
Matrix <Type>::Matrix() {
    this -> row = 0;
    this -> col = 0;
    
    matrix = new Type*[ row ];
    for( int i = 0; i < row; ++i )
        *( matrix + i ) = new Type[ col ];
}

template < typename Type >
Matrix <Type>::Matrix( const int row, const int col ) {
    this -> row = row;
    this -> col = col;

    matrix = new Type*[ row ];
    for( int i = 0; i < row; ++i )
        *( matrix + i ) = new Type[ col ];
    
    for( int i = 0; i < row; i++ ) {
        for( int j = 0; j < col; j++ )
            *(*( matrix + i ) + j ) = 0;
    }
}

template < typename Type >
Matrix <Type>::Matrix( const Matrix &M ) {
    this -> row = M.row;
    this -> col = M.col;

    matrix = new Type*[ row ];
    for( int i = 0; i < row; ++i )
        *( matrix + i ) = new Type[ col ];
    
    for( int i = 0; i < row; i++ ) {
        for( int j = 0; j < col; j++ ) 
            *(*( matrix + i ) + j ) = *(*( M.matrix + i ) + j );
    }
}

template < typename Type >
Matrix <Type>::~Matrix() {
    for( int i = 0; i < row; ++i )
        delete[] *( matrix + i );
    delete[] matrix;
}

template < typename Type >
void Matrix <Type>::fillMatrix() {
    for( int i = 0; i < row; i++ ) {
        for( int j = 0; j < col; j++ ) {
            cout << "Matrix[" << i << "][" << j << "]: ";
            cin >> *(*( matrix + i ) + j );
        }
    }
}

template < typename Type >
Matrix<Type> Matrix <Type>::operator+( const Matrix &A ) {
    Matrix<Type> B( row, col );

    if( row == A.row && col == A.col ) {
        for( int i = 0; i < row; ++i )
            for( int j = 0; j < col; ++j )
                *(*( B.matrix + i ) + j ) = *(*( matrix + i ) + j ) + *(*( A.matrix + i ) + j );
    }

    else
        cout << "No se pueden sumar..." << endl;
    
    return B;
}

template < typename Type >
Matrix<Type> Matrix <Type>::operator-( const Matrix &A ) {
    Matrix<Type> B( row, col );

    if( row == A.row && col == A.col ) {
        for( int i = 0; i < row; ++i )
            for( int j = 0; j < col; ++j )
                *(*( B.matrix + i ) + j ) = *(*( matrix + i ) + j ) - *(*( A.matrix + i ) + j );
    }

    else
        cout << "No se pueden sumar..." << endl;
    
    return B;
}

template < typename Type >
Matrix<Type> Matrix <Type>::operator*( const Matrix &A ) {
    Matrix<Type> B( row, A.col );

    if( col == A.row ) {
        for( int i = 0; i < row; ++i )
            for( int j = 0; j < A.col; ++j )
                for( int k = 0; k < col; ++k )
                    *(*( B.matrix + i ) + j ) += *(*( matrix + i ) + k ) * *(*( A.matrix + k ) + j );
    }

    else 
        cout << "No se pueden multiplicar..." << endl;
    
    return B;
    
}

template < typename Type >
ostream& operator <<( ostream &o, const Matrix <Type> M ) {
	for( int i = 0; i < M.row; i++ ) {
        for( int j = 0; j < M.col; j++ )
            o << *(*( M.matrix + i ) + j ) << " ";
        cout << endl;
    }
	return o;
}

#endif