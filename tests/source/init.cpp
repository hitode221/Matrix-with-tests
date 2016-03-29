#include <matrix.h>
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++){
			auto rows = i;
			auto columns = j;
			Matrix matrix(rows, columns);
			REQUIRE(matrix.getLines() == rows);
			REQUIRE(matrix.getColumns() == columns);
		}
}
SCENARIO ("Matrix fill", "[fill]") {
	Matrix matrix(2, 2);
	matrix.fill("A2x2.txt");
	REQUIRE( matrix[0][0] == 1 );
	REQUIRE( matrix[0][1] == 1 );
	REQUIRE( matrix[1][0] == 2 );
	REQUIRE( matrix[1][1] == 2 );
}

SCENARIO ("Matrix =", "[operator =]"){
	Matrix first(2, 2);
	Matrix second(2, 2);
	second.fill("A2x2.txt");
	first = second;
	REQUIRE( first[0][0] == 1 );
	REQUIRE( first[0][1] == 1 );
	REQUIRE( first[1][0] == 2 );
	REQUIRE( first[1][1] == 2 );

}

