#pragma once
#ifndef __diag_atd__
#define __diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class diag : public matr // ������������ �������
	{
		int mas_diag[20]; //���������� ������
	public: // �������������� ��������� ������
		int InData(ifstream& ifst); // ����
		void InDataD(ifstream& ifst); // ����
		void InDataDD(ifstream& ifst); // ����
		void OutStroki(ofstream& ofst); // �����
		void OutStrokiD(ofstream& ofst); // �����
		void OutStolb(ofstream& ofst); // �����
		void OutOdnMas(ofstream& ofst); // �����
		int Summa();
		int Summa1(int size);

		// ����������� 
		void Multimethod(matr* other, ofstream& ofst);
		void MMSquare(ofstream& ofst);
		void MMDiag(ofstream& ofst);
		void MMNiznDiag(ofstream& ofst);

		diag() {} // �������� ��� �������������
		diag(int mas_check[20], int size_check)
		{
			for (int i = 0; i <= 19; i++)
					this->mas_diag[i] = mas_check[i];

			this->size = size_check;
		}

		int GetMas1(diag* d)
		{
			return d->mas_diag[0];
		}

		int GetMas2(diag* d)
		{
			return d->mas_diag[1];
		}
	};
} // end simple_matrix namespace
#endif


