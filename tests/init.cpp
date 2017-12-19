#include <dicstra.hpp>
#include <catch.hpp>


SCENARIO("compute", "[compute]") {
	std::ofstream fout("f2.txt");
	fout << "6";
	fout << "0 7 9 0 0 14";
	fout << "7 0 10 15 0 0";
	fout << "9 10 0 11 0 2";
	fout << "0 15 11 0 6 0";
	fout << "0 0 0 6 0 9";
	fout << "14 0 2 0 9 0";
	fout.close();
	dicstra init(std::ifstream("f2.txt"));
	double hold;
	init.compute();
	hold = init.show();
	REQUIRE(hold == 11);
}
