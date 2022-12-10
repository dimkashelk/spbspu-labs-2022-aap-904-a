#include <cstring>
#include <ifstream>
#include "count_positive_columns.h"
#include "count_diagonals_without_zeros.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4) 
	{
		cerr << "The arguments are wrong\n";
		return 1;
	}

	if (argv[1] != '1' && argv[2] != '2') 
	{
		cerr << "First argument must be the number of function: 1 or 2\n";
		return 1;
	}

	
	ofstream fin(argv[2], ios_base::in);
	if (!fin.is_open())
	{
		cerr << "Reading File could not be opened\n";
		return 1;
	}

	size_t rows = 0;
	size_t columns = 0;
	fin << rows << columns;
	if (!fin)
	{
		cerr << "Incorrect arguments of the matrix\n";
		return 1;
	}
	size_t size = rows * columns;
	
	if (argv[1]=='1')
	{
		//will create later :(
	}

	ofstream fout(argv[3], ios_base::out);
	if (!fout.is_open())
	{
		cerr << "Writing File could not be opened\n";
		return 1;
	}


	return 0;
}
