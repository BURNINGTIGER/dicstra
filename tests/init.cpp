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
	init.compute();
	double hold[6] = { 0, 7, 9, 20, 20, 11 };
	REQUIRE(init.compare(hold));
}

SCENARIO("compute2", "[compute2]") {
	std::ofstream fout("f3.txt");
	fout << "10" << std::endl;
	fout << "0 1 0 2 3 0 5 0 6 0" << std::endl;
	fout << "1 0 2 0 0 3 3 5 0 5" << std::endl;
	fout << "0 2 0 5 0 1 4 1 0 1" << std::endl;
	fout << "2 0 5 0 2 0 5 2 6 3" << std::endl;
	fout << "3 0 0 2 0 3 6 7 5 4" << std::endl;
	fout << "0 3 1 0 3 0 1 0 0 0" << std::endl;
	fout << "5 3 0 5 6 1 0 7 0 5" << std::endl;
	fout << "0 5 1 2 7 0 7 0 0 5" << std::endl;
	fout << "6 0 0 6 5 0 0 0 0 3" << std::endl;
	fout << "0 5 1 3 4 0 5 5 3 0" ;
	fout.close();
	dicstra init1(std::ifstream("f3.txt"));
	init.compute();
	double hold1[10] = { 0, 1, 3, 2, 3, 4, 4, 4, 6, 4 };
	REQUIRE(init1.compare(hold));
}
