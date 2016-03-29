#include <matrix.h>
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of rows and columns") {

		auto rows = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {

			Matrix matrix(rows, columns);

			THEN("The number of rows and columns must be preserved") {

				REQUIRE(matrix.getLines() == rows);
				REQUIRE(matrix.getColumns() == columns);
			}
		}
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
