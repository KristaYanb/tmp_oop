#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
using namespace simple_matrix;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;
	container c;

	c.In(ifst);
	ofst << "Filled container. " << endl;

	ofst << "Sorted container. " << endl;
	c.sort();
	c.OutSquare(ofst);

	c.Clear();
	ofst << "Empty container. " << endl;

	c.OutSquare(ofst);
	cout << "Stop" << endl;

	return 0;
}