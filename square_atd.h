#pragma once
#ifndef __square_atd__
#define __square_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	
	class square : public matr // квадратная матрица
	{
		//int size; // размерность
		int mas_square[10][10]; //двумерный массив
	public: // переопределяем интерфейс класса
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		square() {} // создание без инициализации.
	};
} // end simple_matrix namespace
#endif