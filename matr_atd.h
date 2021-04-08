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
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;

		static matr* In(ifstream& ifst);
		virtual int InData(ifstream& ifst) = 0; // ����
		virtual void OutStroki(ofstream& ofst) = 0; // �����
		virtual void OutStolb(ofstream& ofst) = 0; // �����
		virtual void OutOdnMas(ofstream& ofst) = 0; // �����
		virtual int Summa() = 0;
		bool Compare(matr* other);
		virtual void OutSquare(ofstream& ofst);
	};
} // end simple_matrix namespace
#endif
