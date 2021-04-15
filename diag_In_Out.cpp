#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void diag::InData(ifstream& ifst) // Ввод параметров диагональной матрицы
	{
		ifst >> size;
		for (int i = 1; i <= size; i++)
			ifst >> mas_diag[i];
	}

	void diag::Out(ofstream& ofst) // Вывод параметров диагональной матрицы
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

	// мультиметод 
	void diag::Multimethod(matr* other, ofstream& ofst)
	{
		other->MMDiag(ofst);
	}

	void diag::MMDiag(ofstream &ofst)
	{ 
		ofst << "Diag and Diag" << endl; 
	}

	void diag::MMSquare(ofstream& ofst)
	{
		ofst << "Square and Diag" << endl;
	}
} // end simple_matrix namespace