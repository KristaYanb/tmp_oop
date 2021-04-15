#include "square_atd.h"
using namespace std;

namespace simple_matrix
{
	void square::InData(ifstream& ifst) // Ввод параметров квадратной матрицы
	{
		ifst >> size;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				ifst >> mas_square[i][j];
	}

	void square::Out(ofstream& ofst) // Вывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				ofst << mas_square[i][j] << " ";
				if (j == size)
					ofst << endl;
			}
	}

	// мультиметод 
	void square::Multimethod(matr *other, ofstream &ofst)
	{ 
		other->MMSquare(ofst); 
	}

	void square::MMSquare(ofstream& ofst)
	{
		ofst << "Square and Square" << endl;
	}

	void square::MMDiag(ofstream& ofst)
	{
		ofst << "Diag and Square" << endl;
	}
} // end simple_matrix namespace