#pragma once
#ifndef MATR_H
#define MATR_H

#include <iostream>
#include <fstream>
#include "exception.cpp"

using namespace std;

template <typename T>
class Matrix;

template <class T>
ostream & operator<<(ostream & output, const Matrix<T> & matrix);

template <class T>
istream & operator>>(istream & input, Matrix<T> & matrix);

template <class T>
class Matrix {
public:
	Matrix() : lines(0), columns(0), elements(nullptr) {}
	Matrix(int _lines, int _columns);
	Matrix(const Matrix <T> & second);
	Matrix& operator= (const Matrix <T> & second);
	void swapMatrix (Matrix <T> & second);
	void fill(char *filename) throw(InitException);
	void print() const;
	T* operator[](int index) const throw(IndexException);
	Matrix operator+(const Matrix <T> & m) const throw(SizesException); 
	Matrix operator*(const Matrix <T> & m) const throw(SizesException);
	bool operator==(const Matrix <T> &matrix) const; 
	int getLines() const;
	int getColumns() const;
	~Matrix();
	
	friend ostream & operator<< <>(std::ostream & output, const Matrix<T> & matrix); 
	friend istream & operator>> <>(std::istream & input, Matrix<T> & matrix) throw(InitException); 
private:
	int lines, columns;
	T **elements;
};

#include "matrix.cpp"

#endif
