#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <condition_variable>

class dicstra
{
public:
	dicstra();
	dicstra(std::ifstream);
	~dicstra();
	void compute();
	void print();
	double show();
private:
	double **length;
	int graf_num;
	double *min_length;
};