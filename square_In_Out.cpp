#include "square_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	int square::InData(ifstream& ifst) // ¬вод параметров квадратной матрицы
	{
		ifst >> size;

		if (ifst.fail())
		{
			cout << "Wrong input size square!" << endl;

			return 0;
		}

		if (size < 0)
		{
			cout << "Error size square!" << endl;

			return 0;
		}

		int tempKey;
		ifst >> tempKey;

		if (ifst.fail())
		{
			cout << "Wrong input k2!" << endl;

			return 0;
		}

		if ((k2 < 0) || (k2 > 2))
		{
			cout << "Error key k2 = " << k2 << endl;

			return 0;
		}

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				ifst >> mas_square[i][j];

				if (ifst.fail())
				{
					cout << "Wrong mas_square!" << endl;
					
					return 0;
				}
			}

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

	void square::InDataS(ifstream& ifst) // ¬вод параметров квадратной матрицы
	{
		ifst >> size;

		for (int i = 0; i <= size - 1; i++)
			for (int j = 0; j <= size - 1; j++)
				ifst >> mas_square[i][j];
	}

	void square::InDataSS(ifstream& ifst) // ¬вод параметров квадратной матрицы
	{
		ifst >> size;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				ifst >> mas_square[i][j];
	}


	void square::OutStroki(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "STROKI "<< k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				ofst << mas_square[i][j] << " ";

				if (j == size)
					ofst << endl;
			}
	}

	void square::OutStrokiS(ofstream& ofst) // ¬ывод параметров квадратной матрицы
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

	void square::OutStolb(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "STOLB " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int j = 1; j <= size; j++)
			for (int i = 1; i <= size; i++)
			{
				ofst << mas_square[i][j] << " ";

				if (i == size)
					ofst << endl;
			}
	}

	void square::OutOdnMas(ofstream& ofst) // ¬ывод параметров квадратной матрицы
	{
		ofst << "It is Square: Size = " << size << endl;
		ofst << "ODN_MASS " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				ofst << mas_square[i][j] << " ";
		
		ofst << endl;
	}

	int square::Summa()
	{
		int summa = 0;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
				summa = summa + mas_square[i][j];
		
		return summa;
	}

	int square::Summa1(int size)
	{
		int summa = 0;

		size = size - 1;
		for (int i = 0; i <= size; i++)
			for (int j = 0; j <= size; j++)
				summa = summa + mas_square[i][j];
		
		return summa;
	}

	void square::OutSquare(ofstream& ofst)
	{
		if (k2 == 0)
			OutStroki(ofst);

		if (k2 == 1)
			OutStolb(ofst);

		if (k2 == 2)
			OutOdnMas(ofst);
	}
} // end simple_matrix namespace