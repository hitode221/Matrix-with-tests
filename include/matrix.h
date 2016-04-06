#pragma once
#ifndef MATR_H
#define MATR_H

#include <iostream>
#include <fstream>

template <typename T>
class CMatrix;

template <class T>
class Matrix {
public:
	Matrix() : lines(0), columns(0), elements(nullptr) {}
	Matrix(int _lines, int _columns);
	Matrix(const Matrix <T> & second);
	Matrix& operator= (const Matrix <T> & second);
	void swapMatrix (Matrix <T> & second);
	void fill(char *filename);
	void print() const;
	T* operator[](int index) const;
	Matrix operator+(const Matrix <T> & m) const; 
	Matrix operator*(const Matrix <T> & m) const;
	bool operator==(const Matrix <T> &matrix) const; 
	int getLines() const;
	int getColumns() const;
	~Matrix();
private:
	int lines, columns;
	T **elements;
};


#endif
