#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void diag::InData(ifstream& ifst) // ¬вод параметров диагональной матрицы
	{
		ifst >> size;
		for (int i = 1; i <= size; i++)
			ifst >> mas_diag[i];
	}

	void diag::Out(ofstream& ofst) // ¬ывод параметров диагональной матрицы
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

	int diag::Summa()
	{
		int summa = 0;
		for (int i = 1; i <= size; i++)
			summa = summa + mas_diag[i];
		return summa;
	}
} // end simple_matrix namespace