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
		void Out1(ofstream& ofst); // �����
		void Out2(ofstream& ofst); // �����
		void Out3(ofstream& ofst); // �����
		square() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif