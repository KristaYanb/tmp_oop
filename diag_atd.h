#pragma once
#ifndef __diag_atd__
#define __diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class diag : public matr // ������������ �������
	{
		//int size; // �����������
		int mas_diag[20]; //���������� ������
	public: // �������������� ��������� ������
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		int Summa();
		diag() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif


