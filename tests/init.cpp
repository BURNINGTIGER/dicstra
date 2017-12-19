#include <dicstra.hpp>
#include <catch.hpp>
#include <iostream>

SCENARIO("compute", "[compute]") {
	dicstra init(std::ifstream("f1.txt"));
	double hold;
	init.compute();
	hold = init.show();
	REQUIRE(hold == 11);
}
