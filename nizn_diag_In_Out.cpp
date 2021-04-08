#include "nizn_diag_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	int nizn_diag::InData(ifstream& ifst) // ���� ���������� ������������ �������
	{
		ifst >> size;

		if (ifst.fail())
		{
			cout << "Wrong input size nizn_diag!" << endl;

			return 0;
		}

		if (size < 0)
		{
			cout << "Error size nizn_diag!" << endl;

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

		int count1 = size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		for (int i = 1; i <= count; i++)
		{
			ifst >> mas_nizn_diag[i];

			if (ifst.fail())
			{
				cout << "Wrong mas_nizn_diag!" << endl;

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

	void nizn_diag::InDataN(ifstream& ifst) // ���� ���������� ������������ �������
	{
		ifst >> size;

		int count1 = size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		for (int i = 0; i <= count-1; i++)
			ifst >> mas_nizn_diag[i];
	}

	void nizn_diag::InDataNN(ifstream& ifst) // ���� ���������� ������������ �������
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
		ofst << "STROKI " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

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

	void nizn_diag::OutStrokiN(ofstream& ofst) // ����� ���������� ������������ �������
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
		ofst << "STOLB " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

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
		ofst << "ODN_MASS " << k2 << endl;
		ofst << "Summa = " << Summa() << endl;

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

	int nizn_diag::Summa1(int size)
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