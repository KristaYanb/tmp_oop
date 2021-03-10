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
		virtual void InData(ifstream& ifst) = 0; // ввод
		//virtual void Out(ofstream& ofst) = 0; // вывод
		virtual void Out1(ofstream& ofst) = 0; // вывод
		virtual void Out2(ofstream& ofst) = 0; // вывод
		virtual void Out3(ofstream& ofst) = 0; // вывод
		virtual int Summa() = 0;
		bool compare(matr* other);
	};
} // end simple_matrix namespace
#endif
