#include "square_atd.h"
using namespace std;

namespace simple_matrix
{
	void square::InData(ifstream& ifst) // ¬вод параметров квадратной матрицы
	{
		ifst >> size;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				ifst >> mas_square[i][j];
	}

	void square::Out(ofstream& ofst) // ¬ывод параметров квадратной матрицы
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

	int square::Summa()
	{
		int summa = 0;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				summa = summa + mas_square[i][j];
		return summa;
	}
} // end simple_matrix namespace