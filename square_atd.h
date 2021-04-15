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
		void Out(ofstream& ofst); // �����

		// ����������� 
		void Multimethod(matr*other, ofstream &ofst); 
		void MMSquare(ofstream &ofst); 
		void MMDiag(ofstream &ofst);

		square() {} // �������� ��� �������������.
	};
} // end simple_matrix namespace
#endif