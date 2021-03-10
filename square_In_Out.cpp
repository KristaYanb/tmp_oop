#include "square_atd.h"
using namespace std;

namespace simple_matrix
{
	void square::InData(ifstream& ifst) // ¬вод параметров квадратной матрицы
	{
		ifst >> size;

		int tempKey;
		ifst >> tempKey;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				ifst >> mas_square[i][j];

		switch (tempKey)
		{
		case 0:
			k2 = key2::STROKI;
			break;
		case 1:
			k2 = key2::STOLB;
			break;
		case 2:
			k2 = key2::ODN_MASS;
			break;
		}
	}

	void square::Out1(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "STROKI "<< k2 << endl;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				ofst << mas_square[i][j] << " ";
				if (j == size)
					ofst << endl;
			}
	}

	void square::Out2(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "STOLB " << k2 << endl;
		for (int j = 1; j <= size; j++)
			for (int i = 1; i <= size; i++)
			{
				ofst << mas_square[i][j] << " ";
				if (i == size)
					ofst << endl;
			}
	}

	void square::Out3(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "ODN_MASS " << k2 << endl;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				ofst << mas_square[i][j] << " ";
			}
		ofst << endl;

	int square::Summa()
	{
		int summa = 0;
		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				summa = summa + mas_square[i][j];
		return summa;
	}
} // end simple_matrix namespace