#include "nizn_diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void nizn_diag::InData(ifstream& ifst) // ���� ���������� ������������ �������
	{
		ifst >> size;
		int count1 = size;
		int count = 0;
		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		for (int i = 1; i <= count; i++)
			ifst >> mas_nizn_diag[i];
	}

	void nizn_diag::OutStroki(ofstream& ofst) // ����� ���������� ������������ �������
	{
		ofst << "It is Nizn_Diag: Size = " << size << endl;
		for (int i = 1, ii = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				if (j <= i)
					ofst << mas_nizn_diag[ii++] << " ";
				else
					ofst << 0 << " ";
				if (j == size)
					ofst << endl;
			}
	}

	void nizn_diag::OutStolb(ofstream& ofst) // ����� ���������� ������������ �������
	{
		ofst << "It is Nizn_Diag matrix: Size = " << size << endl;
		for (int i = 1, ii = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				if (i <= j)
					ofst << mas_nizn_diag[ii++] << " ";
				else
					ofst << 0 << " ";
				if (j == size)
					ofst << endl;
			}
	}

	void nizn_diag::OutOdnMas(ofstream& ofst) // ����� ���������� ������������ �������
	{
		ofst << "It is Nizn_Diag matrix: Size = " << size << endl;
		for (int i = 1, ii = 1; i <= size; i++)
			for (int j = 1; j <= size; j++)
			{
				if (j <= i)
					ofst << mas_nizn_diag[ii++] << " ";
				else
					ofst << 0 << " ";
			}
		ofst << endl;
	}

	int nizn_diag::Summa()
	{
		int count1 = size;
		int count = 0;
		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		int summa = 0;
		for (int i = 1; i <= count; i++)
			summa = summa + mas_nizn_diag[i];

		return summa;
	}
} // end simple_matrix namespace