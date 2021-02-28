#pragma once
#ifndef __diag_atd__
#define __diag_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	class diag : public matr // диагональная матрица
	{
		//int size; // размерность
		int mas_diag[20]; //одномерный массив
	public: // переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out1(ofstream& ofst); // вывод
		void Out2(ofstream& ofst); // вывод
		void Out3(ofstream& ofst); // вывод
		diag() {} // создание без инициализации.
	};
} // end simple_matrix namespace
#endif


