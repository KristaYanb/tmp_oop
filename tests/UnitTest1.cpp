#include "pch.h"
#include "CppUnitTest.h"

#include "../merge_oop/matr_atd.h"
#include "../merge_oop/matr_In.cpp"
#include "../merge_oop/merge_oop.cpp"
#include "../merge_oop/nizn_diag_atd.h"
#include "../merge_oop/nizn_diag_In_Out.cpp"
#include "../merge_oop/square_atd.h"
#include "../merge_oop/square_In_Out.cpp"
#include "../merge_oop/container_atd.h"
#include "../merge_oop/container_In_Out.cpp"
#include "../merge_oop/diag_atd.h"
#include "../merge_oop/diag_In_Out.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		string Read(const char* filename)
		{
			ifstream ifst(filename);
			string s;
			while (!ifst.eof())
			{
				ifst >> s;
			}
			ifst.close();
			return s;
		}
		
		TEST_METHOD(TestOut)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			c.In(ifst);
			c.Out(ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutSquare)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			c.In(ifst);
			c.OutSquare(ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outSquareMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutNiznDiag)
		{
			ifstream ifst("input_nizn_diag.txt");
			ofstream ofst("output_nizn_diag.txt");
			//nizn_diag actual;
			nizn_diag* actual = new nizn_diag;
			actual->InDataNN(ifst);
			actual->OutStrokiN(ofst);

			string s1 = Read("output_nizn_diag.txt");
			string s2 = Read("out_nizn_diag_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutDiag)
		{
			ifstream ifst("input_diag.txt");
			ofstream ofst("output_diag.txt");
			//nizn_diag actual;
			diag* actual = new diag;
			actual->InDataDD(ifst);
			actual->OutStrokiD(ofst);

			string s1 = Read("output_diag.txt");
			string s2 = Read("out_diag_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutSquare2)
		{
			ifstream ifst("input_square.txt");
			ofstream ofst("output_square.txt");
			//nizn_diag actual;
			square* actual = new square;
			actual->InDataSS(ifst);
			actual->OutStrokiS(ofst);

			string s1 = Read("output_square.txt");
			string s2 = Read("out_square_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestSort)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			c.In(ifst);
			c.sort();
			c.Out(ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outSortMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestClear)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			c.In(ifst);
			c.Out(ofst);
			c.Clear();
			c.Out(ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outClear.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(SummaSquare)
		{
			int mas_check[10][10];
			int size_check = 10;
			int key_check = 2;
			for (int i = 0; i <= 9; i++)
				for (int j = 0; j <= 9; j++)
				{
					mas_check[i][j] = 1;
				}

			square* nb = new square(mas_check, size_check);
			int actual = nb->Summa1(size_check);
			Assert::AreEqual(100, actual);

			int mas_check2[10][10];
			int size_check2 = 9;
			for (int i = 0; i <= 9; i++)
				for (int j = 0; j <= 9; j++)
				{
					mas_check2[i][j] = 1;
					//if ((i == 9) || (j == 9))
						//mas_check2[i][j] = 0;
				}

			square* nb2 = new square(mas_check2, size_check2);
			int actual2 = nb2->Summa1(size_check2);
			Assert::AreEqual(81, actual2);

			int mas_check3[10][10];
			int size_check3 = 8;
			for (int i = 0; i <= 9; i++)
				for (int j = 0; j <= 9; j++)
				{
					mas_check3[i][j] = 1;
					//if ((i == 9) || (j == 9) || (i == 8) || (j == 8))
						//mas_check2[i][j] = 0;
				}

			square* nb3 = new square(mas_check3, size_check3);
			int actual3 = nb3->Summa1(size_check3);
			Assert::AreEqual(64, actual3);
		}

		TEST_METHOD(SummaDiag)
		{
			int mas_check[20];
			int size_check = 20;
			for (int i = 0; i <= 19; i++)
				mas_check[i] = 1;

			diag* nb = new diag(mas_check, size_check);
			int actual = nb->Summa1(size_check);
			Assert::AreEqual(20, actual);

			int mas_check2[20];
			int size_check2 = 19;
			for (int i = 0; i <= 19; i++)
			{
				mas_check2[i] = 1;
				//if (i == 19)
					//mas_check2[i] = 0;
			}

			diag* nb2 = new diag(mas_check2, size_check2);
			int actual2 = nb2->Summa1(size_check2);
			Assert::AreEqual(19, actual2);

			int mas_check3[20];
			int size_check3 = 18;
			for (int i = 0; i <= 19; i++)
			{
				mas_check3[i] = 1;
				//if ((i == 19) || (i == 18))
					//mas_check2[i] = 0;
			}

			diag* nb3 = new diag(mas_check3, size_check3);
			int actual3 = nb3->Summa1(size_check3);
			Assert::AreEqual(18, actual3);
		}

		TEST_METHOD(SummaNiznDiag)
		{
			int mas_check[50];
			int size_check = 9;
			for (int i = 0; i <= 49; i++)
				mas_check[i] = 1;

			nizn_diag* nb = new nizn_diag(mas_check, size_check);
			int actual = nb->Summa1(size_check);
			Assert::AreEqual(45, actual);

			int mas_check2[50];
			int size_check2 = 8;
			for (int i = 0; i <= 49; i++)
			{
				mas_check2[i] = 1;
			}

			nizn_diag* nb2 = new nizn_diag(mas_check2, size_check2);
			int actual2 = nb2->Summa1(size_check2);
			Assert::AreEqual(36, actual2);

			int mas_check3[50];
			int size_check3 = 7;
			for (int i = 0; i <= 49; i++)
			{
				mas_check3[i] = 1;
			}

			nizn_diag* nb3 = new nizn_diag(mas_check3, size_check3);
			int actual3 = nb3->Summa1(size_check3);
			Assert::AreEqual(28, actual3);
		}

		TEST_METHOD(TestInSquare)
		{
			ifstream ifst("input_square.txt");
			int mas_check[10][10];
			int size_check = 2;
			int k = 1;
			for (int i = 0; i <= 1; i++)
				for (int j = 0; j <= 1; j++)
				{
					mas_check[i][j] = k;
					k++;
				}
			square* sd = new square(mas_check, size_check);

			square* actual = new square;
			actual->InDataS(ifst);

			Assert::AreEqual(sd->size, actual->size);
			Assert::AreEqual(sd->get_mas1(sd), actual->get_mas1(actual));
			Assert::AreEqual(sd->get_mas2(sd), actual->get_mas2(actual));
			Assert::AreEqual(sd->get_mas3(sd), actual->get_mas3(actual));
			Assert::AreEqual(sd->get_mas4(sd), actual->get_mas4(actual));
		}

		TEST_METHOD(TestInDiag)
		{
			ifstream ifst("input_diag.txt");
			int mas_check[20];
			int size_check = 2;
			int j = 1;
			for (int i = 0; i <= 1; i++)
			{
				mas_check[i] = j;
				j++;
			}
			diag* sd = new diag(mas_check, size_check);

			diag* actual = new diag;
			actual->InDataD(ifst);

			Assert::AreEqual(sd->size, actual->size);
			Assert::AreEqual(sd->get_mas1(sd), actual->get_mas1(actual));
			Assert::AreEqual(sd->get_mas2(sd), actual->get_mas2(actual));
		}

		TEST_METHOD(TestInNiznDiag)
		{
			ifstream ifst("input_nizn_diag.txt");
			int mas_check[50];
			int size_check = 2;
			int count1 = size_check;
			int count = 0;
			while (count1 != 0)
			{
				count = count + count1;
				count1 = count1 - 1;
			}
			int j = 1;
			for (int i = 0; i <= count - 1; i++)
			{
				mas_check[i] = j;
				j++;
			}
			nizn_diag* sd = new nizn_diag(mas_check, size_check);

			nizn_diag* actual = new nizn_diag;
			actual->InDataN(ifst);

			Assert::AreEqual(sd->size, actual->size);
			Assert::AreEqual(sd->get_mas1(sd), actual->get_mas1(actual));
			Assert::AreEqual(sd->get_mas2(sd), actual->get_mas2(actual));
			Assert::AreEqual(sd->get_mas3(sd), actual->get_mas3(actual));
		}
	};
}
