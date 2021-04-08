#pragma once
#ifndef __square_atd__
#define __square_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class square : public matr // ���������� �������
	{
		int mas_square[10][10]; //��������� ������
	public: // �������������� ��������� ������
		int InData(ifstream& ifst); // ����
		void InDataS(ifstream& ifst); // ����
		void InDataSS(ifstream& ifst); // ����
		void OutStroki(ofstream& ofst); // �����
		void OutStrokiS(ofstream& ofst); // �����
		void OutStolb(ofstream& ofst); // �����
		void OutOdnMas(ofstream& ofst); // �����
		int Summa();
		void OutSquare(ofstream& ofst);

		int Summa1(int size);
		square() {} // �������� ��� �������������

		square(int mas_check[10][10], int size_check)
		{
			for (int i = 0; i <= 9; i++)
				for (int j = 0; j <= 9; j++)
				{
					this->mas_square[i][j] = mas_check[i][j];
				}
			
			this->size = size_check;
		}

		int GetMas1(square* s)
		{
			return s->mas_square[0][0];
		}

		int GetMas2(square* s)
		{
			return s->mas_square[0][1];
		}

		int GetMas3(square* s)
		{
			return s->mas_square[1][0];
		}

		int GetMas4(square* s)
		{
			return s->mas_square[1][1];
		}
	};
} // end simple_matrix namespace
#endif