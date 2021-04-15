#pragma once
#ifndef __nizn_diag_atd__
#define __nizn_diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class nizn_diag : public matr // диагональная матрица
	{
		//int size; // размерность
		int mas_nizn_diag[50]; //одномерный массив
	public: // переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод

		nizn_diag() {} // создание без инициализации.
	};
} // end simple_matrix namespace
#endif