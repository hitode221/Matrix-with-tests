#ifndef Matrix_h
#define Matrix_h
#include <fstream>
#include <iostream>

template <class T>
class Matrix {
public:
	Matrix<T>() : lines(0), columns(0), elements(nullptr) {}
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
