#pragma once
#ifndef __square_atd__
#define __square_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class square : public matr // ���������� �������
	{
		//int size; // �����������
		int mas_square[10][10]; //��������� ������
	public: // �������������� ��������� ������
		void InData(ifstream& ifst); // ����
		void OutStroki(ofstream& ofst); // �����
		void OutStolb(ofstream& ofst); // �����
		void OutOdnMas(ofstream& ofst); // �����
		int Summa();
		//void Out(ofstream& ofst); // �����
		void OutSquare(ofstream& ofst);
		square() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif