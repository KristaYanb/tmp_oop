#pragma once
#ifndef __nizn_diag_atd__
#define __nizn_diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class nizn_diag : public matr // ������������ �������
	{
		//int size; // �����������
		int mas_nizn_diag[50]; //���������� ������
	public: // �������������� ��������� ������
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����

		nizn_diag() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif