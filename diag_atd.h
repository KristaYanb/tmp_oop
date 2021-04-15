#pragma once
#ifndef __diag_atd__
#define __diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class diag : public matr // диагональная матрица
	{
		int mas_diag[20]; //одномерный массив
	public: // переопределяем интерфейс класса
		int InData(ifstream& ifst); // ввод
		void InDataD(ifstream& ifst); // ввод
		void InDataDD(ifstream& ifst); // ввод
		void OutStroki(ofstream& ofst); // вывод
		void OutStrokiD(ofstream& ofst); // вывод
		void OutStolb(ofstream& ofst); // вывод
		void OutOdnMas(ofstream& ofst); // вывод
		int Summa();
		int Summa1(int size);

		// мультиметод 
		void Multimethod(matr* other, ofstream& ofst);
		void MMSquare(ofstream& ofst);
		void MMDiag(ofstream& ofst);
		void MMNiznDiag(ofstream& ofst);

		diag() {} // создание без инициализации
		diag(int mas_check[20], int size_check)
		{
			for (int i = 0; i <= 19; i++)
					this->mas_diag[i] = mas_check[i];

			this->size = size_check;
		}

		int GetMas1(diag* d)
		{
			return d->mas_diag[0];
		}

		int GetMas2(diag* d)
		{
			return d->mas_diag[1];
		}
	};
} // end simple_matrix namespace
#endif


