#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void diag::InData(ifstream& ifst) // ¬вод параметров диагональной матрицы
	{
		ifst >> size;
		int tempKey;
		ifst >> tempKey;

		for (int i = 1; i <= size; i++)
			ifst >> mas_diag[i];

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

	void diag::OutStroki(ofstream& ofst) // ¬ывод параметров диагональной матрицы
	{
		ofst << "It is Diag: Size = " << size << endl;
		ofst << "STROKI " << k2 << endl;
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
} // end simple_matrix namespace