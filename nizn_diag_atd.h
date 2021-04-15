#pragma once
#ifndef __nizn_diag_atd__
#define __nizn_diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class nizn_diag : public matr // диагональная матрица
	{
		int mas_nizn_diag[50]; //одномерный массив
	public: // переопределяем интерфейс класса
		int InData(ifstream& ifst); // ввод
		void InDataN(ifstream& ifst); // ввод
		void InDataNN(ifstream& ifst); // ввод
		void OutStroki(ofstream& ofst); // вывод
		void OutStrokiN(ofstream& ofst); // вывод
		void OutStolb(ofstream& ofst); // вывод
		void OutOdnMas(ofstream& ofst); // вывод

		// мультиметод 
		void Multimethod(matr* other, ofstream& ofst);
		void MMSquare(ofstream& ofst);
		void MMDiag(ofstream& ofst);
		void MMNiznDiag(ofstream& ofst);

		int Summa();
		int Summa1(int size);

		nizn_diag() {} // создание без инициализации
		nizn_diag(int mas_check[50], int size_check)
		{
			for (int i = 0; i <= 49; i++)
				this->mas_nizn_diag[i] = mas_check[i];

			this->size = size_check;
		}

		int GetMas1(nizn_diag* n)
		{
			return n->mas_nizn_diag[0];
		}

		int GetMas2(nizn_diag* n)
		{
			return n->mas_nizn_diag[1];
		}

		int GetMas3(nizn_diag* n)
		{
			return n->mas_nizn_diag[2];
		}
	};
} // end simple_matrix namespace
#endif