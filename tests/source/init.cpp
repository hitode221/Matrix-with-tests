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
	fstream file("A.txt");
	filee >> matrix;
	REQUIRE( matrix[0][0] == 1 );
	REQUIRE( matrix[0][1] == 1 );
	REQUIRE( matrix[1][0] == 2 );
	REQUIRE( matrix[1][1] == 2 );
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
}

/*SCENARIO("Matrix +", "[addition]") {
	Matrix<int> A(2, 2);
	A.fill("A.txt");
	Matrix<int> B(2, 2);
	B.fill("B.txt");
	Matrix<int> expected(2, 2);
	expected.fill("A+B.txt");
	Matrix<int> result = A + B;
	REQUIRE(result == expected);
}*/

/*SCENARIO("Matrix *", "[multiplication]") {
	Matrix<int> A(2, 2);
	A.fill("A.txt");
	Matrix<int> B(2, 2);
	B.fill("B.txt");
	Matrix<int> expected(2, 2);
	expected.fill("A*B.txt");
	Matrix<int> result = A * B;
	REQUIRE(result == expected);
}*/
SCENARIO("Matrix get line by index", "[get_line]") {
	Matrix<int> matrix(2, 2);
	matrix.fill("A.txt");
	int first_line[2] = {1, 1};
	int second_line[2] = {2, 2};
	REQUIRE( matrix[0][0] == first_line[0] );
	REQUIRE ( matrix [0][1] == first_line[1]);
	REQUIRE( matrix[1][0] == second_line[0] );
	REQUIRE ( matrix [1][1] == second_line[1]);
}

SCENARIO("print", "[print]"){
	Matrix<int> matrix(2, 2);
	matrix.fill("A.txt");
	//cout << matrix;
	matrix.print();
}


