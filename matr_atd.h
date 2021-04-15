#pragma once
#ifndef __matr_atd__
#define __matr_atd__
#include <fstream>
using namespace std;

namespace simple_matrix
{
	class matr
	{
	public:
		int size;

		static matr* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ����
		virtual void Out(ofstream& ofst) = 0; // �����
		
		// ����������� 
		virtual void Multimethod(matr*other, ofstream &ofst) = 0;
		virtual void MMSquare(ofstream &ofst) = 0; 
		virtual void MMDiag(ofstream &ofst) = 0;
	};
} // end simple_matrix namespace
#endif
