
#pragma once
#include <exception>
#include "iostream"
using namespace std;

class MatrixException : public std :: exception{
public: 
	MatrixException() : exception("Unknown exception"){}
	MatrixException(const char * const &_message) : std :: exception(_message){} 
};

class SizesException : public MatrixException{
public:
	SizesException() : MatrixException("Wrong sizes of matrix"){};
};

class InitException : public MatrixException{
public:
	InitException() : MatrixException("Initilization error"){};

};

class IndexException : public MatrixException{
public:
	IndexException() : MatrixException("There is no such index"){};
};
