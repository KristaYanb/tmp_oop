#include "matr_atd.h"
#include "square_atd.h"
#include "diag_atd.h"
#include "nizn_diag_atd.h"
using namespace std;

namespace simple_matrix
{
	matr* matr::In(ifstream& ifst) // ¬вод параметров обобщенной матрицы
	{
		matr* sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new square;
			break;
		case 2:
			sp = new diag;
			break;
		/*case 3:
			sp = new nizn_diag;
			break;*/
		default:
			return 0;
		}
		sp->InData(ifst);
		return sp;
	}
} // end simple_matrix namespace