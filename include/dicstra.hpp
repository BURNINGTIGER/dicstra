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
	bool compare(double *);
private:
	double **length;
	int graf_num;
	double *min_length;
	double max;
};
