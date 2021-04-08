#include "diag_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	int diag::InData(ifstream& ifst) // ¬вод параметров диагональной матрицы
	{
		ifst >> size;

		if (ifst.fail())
		{
			cout << "Wrong input size diag!" << endl;
			
			return 0;
		}

		if (size < 0)
		{
			cout << "Error size diag!" << endl;
			
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
		{
			ifst >> mas_diag[i];

			if (ifst.fail())
			{
				cout << "Wrong mas_diag!" << endl;
				
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

	void diag::InDataD(ifstream& ifst) // ¬вод параметров диагональной матрицы
	{
		ifst >> size;

		for (int i = 0; i <= size-1; i++)
			ifst >> mas_diag[i];
	}

	void diag::InDataDD(ifstream& ifst) // ¬вод параметров диагональной матрицы
	{
		ifst >> size;

		for (int i = 1; i <= size; i++)
			ifst >> mas_diag[i];
	}

	void diag::OutStroki(ofstream& ofst) // ¬ывод параметров диагональной матрицы
	{
		ofst << "It is Diag: Size = " << size << endl;
		ofst << "STROKI " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				if (i == j)
					ofst << mas_diag[i] << " ";

				else
					ofst << "0 ";

				if (j == size)
					ofst << endl;
			}
	}

	void diag::OutStrokiD(ofstream& ofst) // ¬ывод параметров диагональной матрицы
	{
		ofst << "It is Diag: Size = " << size << endl;

		for (int i = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				if (i == j)
					ofst << mas_diag[i] << " ";

				else
					ofst << "0 ";

				if (j == size)
					ofst << endl;
			}
	}

	void diag::OutStolb(ofstream& ofst) // ¬ывод параметров диагональной матрицы
	{
		ofst << "It is Diag: Size = " << size << endl;
		ofst << "STOLB " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int j = 1; j <= size; j++)
			for (int i = 1; i <= size; i++)
			{
				if (j == i)
					ofst << mas_diag[i] << " ";

				else
					ofst << "0 ";

				if (i == size)
					ofst << endl;
			}
	}

	void diag::OutOdnMas(ofstream& ofst) // ¬ывод параметров диагональной матрицы
	{
		ofst << "It is Diag: Size = " << size << endl;
		ofst << "ODN_MASS " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

		for (int j = 1; j <= size; j++)
			for (int i = 1; i <= size; i++)
			{
				if (j == i)
					ofst << mas_diag[i] << " ";

				else
					ofst << "0 ";
			}

		ofst << endl;
	}

	int diag::Summa()
	{
		int summa = 0;

		for (int i = 1; i <= size; i++)
			summa = summa + mas_diag[i];

		return summa;
	}

	int diag::Summa1(int size)
	{
		int summa = 0;
		size = size - 1;

		for (int i = 0; i <= size; i++)
			summa = summa + mas_diag[i];

		return summa;
	}
} // end simple_matrix namespace