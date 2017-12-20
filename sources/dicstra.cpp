#include "dicstra.hpp"

dicstra::dicstra()
{
	graf_num = 0;
	length = nullptr;
	min_length = nullptr;
}

dicstra::dicstra(std::ifstream  input)
{
	if (!input)
	{
		throw std::logic_error("Error! File not found!");
	}
	input >> graf_num;
	min_length = new double[graf_num];
	length = new double*[graf_num];
	for (int i = 0; i < graf_num; i++)
	{

		length[i] = new double[graf_num];
		min_length[i] = 10000;
	}

	min_length[0] = 0;

	for (int i = 0; i < graf_num; i++)
	{
		for (int j = 0; j < graf_num; j++)
		{
			input >> length[i][j];
		}
	}
}

dicstra::~dicstra()
{
	for (int i = 0; i < graf_num; i++)
		delete[] length[i];
	delete[] length;
	graf_num = 0;
	delete[]min_length;
}
void dicstra::compute()
{
	int* passed = new int[graf_num];
	int minindex;
	double min;
	double temp;
	int j = 0;
	for (int i = 0; i<graf_num; i++)
	{
		passed[i] = 1;
	}
	do {
		minindex = -1;
		min = 10000;

		for (int i = 0; i<graf_num; i++)
		{
			if ((passed[i] == 1) && (min_length[i]<min))
			{
				min = min_length[i];
				minindex = i;
			}
		}
		if (minindex != -1)
		{
			for (int i = 0; i<graf_num; i++)
			{
				if (length[minindex][i] > 0)
				{
					temp = min + length[minindex][i];
					if (temp < min_length[i])
						min_length[i] = temp;
				}
			}
			passed[minindex] = 0;
		}
	} while (minindex > -1);
}

void dicstra::print()
{
	for (int i = 0; i < graf_num; i++)
		std::cout << min_length[i] << " ";
}

bool dicstra::compare(double * result){
	bool same = true;
	for (int i = 0; i < graf_num; i++)
	if (min_length[i]!=result[i])
		same = false;
	return same;
}

