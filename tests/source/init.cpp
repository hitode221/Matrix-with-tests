#include <matrix.h>
#include <catch.hpp>
#include <fstream>
#include <iostream>

SCENARIO("Matrix init", "[init]") {
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++){
			auto rows = i;
			auto columns = j;
			Matrix<int> matrix(rows, columns);
			REQUIRE(matrix.getLines() == rows);
			REQUIRE(matrix.getColumns() == columns);
		}
}
SCENARIO("Matrix fill", "[fill]") {
	Matrix<int> matrix(2, 2);
	Matrix <char> matrixC(2, 2);
	Matrix<int> matrixB(3, 3);
	bool flag = false;
	fstream file("A.txt");
	fstream fileC("Char1.txt");
	file >> matrix;
	REQUIRE( matrix[0][0] == 1 );
	REQUIRE( matrix[0][1] == 1 );
	REQUIRE( matrix[1][0] == 2 );
	REQUIRE( matrix[1][1] == 2 );
	fileC >> matrixC;
	REQUIRE(matrixC[0][0] == 'a');
	REQUIRE(matrixC[0][1] == 'b');
	REQUIRE(matrixC[1][0] == 'c');
	REQUIRE(matrixC[1][1] == 'd');
	try {
		file >> matrixB;
	}
	catch (InitException &e){
		flag = true;
	}
	REQUIRE(flag);
	flag = false;
	try {
		fileC >> matrix;
	}
	catch (InitException &e){
		flag = true;
	}
	REQUIRE(flag);

}

SCENARIO ("Matrix =", "[operator =]"){
	Matrix<int> first(2, 2);
	Matrix<int> second(2, 2);
	second.fill("A.txt");
	first = second;
	REQUIRE( first[0][0] == 1 );
	REQUIRE( first[0][1] == 1 );
	REQUIRE( first[1][0] == 2 );
	REQUIRE( first[1][1] == 2 );
	Matrix<char> firstC(2, 2);
	Matrix<char> secondC(2, 2);
	second.fill("Char1.txt");
	firstC = secondC;
	REQUIRE( firstC[0][0] == 'a' );
	REQUIRE( firstC[0][1] == 'b' );
	REQUIRE( firstC[1][0] == 'c' );
	REQUIRE( firstC[1][1] == 'd' );
}

SCENARIO("Matrix +", "[addition]") {
	bool flag = false;
	Matrix<int> A(2, 2);
	A.fill("A.txt");
	Matrix<int> B(2, 2);
	B.fill("B.txt");
	Matrix<int> C(3, 3);
	C.fill("D.txt");
	Matrix<int> expected(2, 2);
	expected.fill("A+B.txt");
	Matrix<int> result = A + B;
	REQUIRE(result == expected);
	try {
		A+C;
	}
	catch(SizesException &e){
		flag = true;
	}
	REQUIRE(flag);
}

SCENARIO("Matrix *", "[multiplication]") {
	bool flag = false;
	Matrix<int> A(2, 2);
	A.fill("A.txt");
	Matrix<int> B(2, 2);
	B.fill("B.txt");
	Matrix<int> C(3, 3);
	C.fill("D.txt");
	Matrix<int> expected(2, 2);
	expected.fill("A*B.txt");
	Matrix<int> result = A * B;
	REQUIRE(result == expected);
	try {
		A*C;
	}
	catch(SizesException &e){
		flag = true;
	}
	REQUIRE(flag);
}
SCENARIO("Matrix get line by index", "[get_line]") {
	Matrix<int> matrix(2, 2);
	Matrix<char> matrixC(2, 2);
	bool flag = false;
	matrix.fill("A.txt");
	matrixC.fill("Char1.txt");
	int first_line[2] = {1, 1};
	int second_line[2] = {2, 2};
	char first_line_c[2] = {'a', 'b'};
	char second_line_c[2] = {'c', 'd'};
	REQUIRE( matrixC[0][0] == first_line_c[0] );
	REQUIRE ( matrixC [0][1] == first_line_c[1]);
	REQUIRE( matrixC[1][0] == second_line_c[0] );
	REQUIRE ( matrixC [1][1] == second_line_c[1]);
	REQUIRE( matrix[0][0] == first_line[0] );
	REQUIRE ( matrix [0][1] == first_line[1]);
	REQUIRE( matrix[1][0] == second_line[0] );
	REQUIRE ( matrix [1][1] == second_line[1]);
	try{
		matrix[3][1] = 1;
	}
	catch (IndexException &e){
		flag = true;
	}
	REQUIRE(flag);
}
SCENARIO("operator==", "[operator==]"){
	Matrix <int> A(2, 2); 
	Matrix <int> B(2, 2);
	A.fill("A.txt");
	B.fill("A.txt");
	REQUIRE(A==B);
}
SCENARIO("print", "[print]"){
	Matrix<int> matrix(2, 2);
	Matrix <char> matrixC(2, 2);
	matrix.fill("A.txt");
	matrixC.fill("Char1.txt");
	cout << matrix << matrixC;
}


