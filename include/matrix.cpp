#include <time.h>
#include "matrix.h"
using namespace std;

#ifndef MATR_CPP
#define MATR_CPP


template <class T>	
Matrix<T>::Matrix(int _lines, int _columns) : elements(new T*[_lines]), lines(_lines), columns(_columns) {
	for (int i = 0; i < lines; i++){
		elements[i] = new T[columns];
	}
}
template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) : elements(new T*[matrix.lines]), lines(matrix.lines), columns(matrix.columns) {
	for (int i = 0; i < lines; i++){
		elements[i] = new T[columns];
		for (int j = 0; j < columns; j++){
			elements[i][j] = matrix.elements[i][j];
		}
	}
}
template <class T>
void Matrix<T>:: swapMatrix(Matrix <T> & second){
	swap(lines, second.lines);
	swap(columns, second.columns);
	swap(elements, second.elements);
}
template <class T>
void Matrix<T> :: fill(char *filename){
	fstream file(filename);
	if (!file.is_open()){
		throw InitException();
	}
	for (unsigned int i = 0; i < lines; i++){
		for (unsigned int j = 0; j < columns; j++){
			if (file.eof()){ 
				throw InitException();
			}
			file >> matrix.elements[i][j];
		}
	}
}
template <class T>
void Matrix<T> :: print() const {
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < columns; j++){
			cout << elements[i][j] << " ";
		}
		cout << "\n";
	}
}
template <class T>
int Matrix<T>::getLines() const{
		return lines;
}
template <class T>
int Matrix<T> :: getColumns() const{
		return columns;
}
template <class T>
Matrix<T> & Matrix<T> :: operator=(const Matrix<T> & second){
	if (this != &second) {
		Matrix(second).swapMatrix(*this);
	}
	return *this;
}
template <class T>
T* Matrix<T> :: operator[] (int index) const throw (IndexException){
	if (index >= lines || index < 0) throw IndexException();
	return elements[index];
}
template <class T>
Matrix<T> Matrix<T> :: operator+(const Matrix& m) const throw (SizesException){
	if (columns != m.columns || lines != m.lines){ 
		throw SizesException();
	}
	Matrix <T> temp(lines, columns);
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < columns; j++){
			temp[i][j] = elements[i][j] + m[i][j];
		}
	}
	return temp;
}
template <class T>
Matrix<T> Matrix<T> :: operator*(const Matrix <T> &m) const throw(SizesException){
	if (columns != m.lines){
		throw SizesException();
	}
	Matrix <T> result(lines, m.columns);
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < m.columns; j++){
			result[i][j] = 0;
			for (int k = 0; k < m.lines; k++){
				result[i][j] += elements[i][k] * m[k][j];
			}
		}
	}
	return result;
}
template <class T>
bool Matrix<T> :: operator==(const Matrix <T> & matrix) const{
    if ( lines != matrix.lines || columns != matrix.columns ) {
        return false;
    }
    for (unsigned int i = 0; i < lines; ++i) {
        for (unsigned int j = 0; j < columns; ++j) {
            if ( elements[i][j] != matrix.elements[i][j] ) {
                return false;
            }
        }
    }
    return true;
}
template <class T>
Matrix<T> :: ~Matrix(){
	for (int i = 0; i < lines; i++){
		delete [] elements[i];
	}
	delete [] elements;
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const Matrix<T>& matrix){
	for (unsigned int i = 0; i < matrix.lines; i++){
		for (unsigned int j = 0; j < matrix.columns; j++){
			stream << matrix.elements[i][j] << " ";
		}
		stream << '\n';
	}
	return stream;
}

template <typename T>
std::istream& operator>> (std::istream& stream, Matrix<T>& matrix) throw (InitException){
	for (unsigned int i = 0; i < matrix.lines; i++){
		for (unsigned int j = 0; j < matrix.columns; j++){
			if (stream.eof()) 
				throw InitException();
			stream >> matrix.elements[i][j];
		}
	}
	return stream;
}
#endif
