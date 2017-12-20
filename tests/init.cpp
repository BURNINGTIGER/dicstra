#include <dicstra.hpp>
#include <catch.hpp>
#include <iostream>
#include <fstream>

SCENARIO("compute", "[compute]") {
	std::ofstream fout("f2.txt");
	fout << "6" << std::endl;
	fout << "0 7 9 0 0 14" << std::endl;
	fout << "7 0 10 15 0 0" << std::endl;
	fout << "9 10 0 11 0 2" << std::endl;
	fout << "0 15 11 0 6 0" << std::endl;
	fout << "0 0 0 6 0 9" << std::endl;
	fout << "14 0 2 0 9 0" ;
	fout.close();
	dicstra init(std::ifstream("f2.txt"));
	double hold[6] = { 0, 7, 9, 20, 20, 11 };
	REQUIRE(a.compare(hold));
}
