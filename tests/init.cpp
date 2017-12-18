#include <dicstra.hpp>
#include <catch.hpp>


SCENARIO("init", "[init]") {
	dicstra init();
	double hold;
	hold=init.show()
	REQUIRE(hold == nullptr);
}

SCENARIO("compute", "[compute]") {
	dicstra init(std::ifstream("f1.txt"));
	double hold;
	init.compute();
	hold = init.show()
	REQUIRE(hold == [11]);
}
