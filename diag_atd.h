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
		void Out1(ofstream& ofst); // �����
		void Out2(ofstream& ofst); // �����
		void Out3(ofstream& ofst); // �����
		diag() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif


