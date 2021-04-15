#include "container_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	node::~node() {}

	bool node::AddNode(ifstream& ifst)
	{
		m = matr::In(ifst);

		if (m == NULL)
			return false;

		else
			return true;
	}

	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			node* tmpNode = new node;
			if (tmpNode->AddNode(ifst))
			{
				size++;

				if (head != NULL)
				{
					tmpNode->next = head;
					head = tmpNode;
				}

				else
				{
					tmpNode->next = NULL;
					head = tmpNode;
				}
			}
		}
	}

	int node::SummaNode(ofstream& ofst)
	{
		return m->Summa();;
	}

	bool node::OutputNode(ofstream& ofst)
	{
		if (m->k2 == 0)
		{
			m->OutStroki(ofst);

			return true;
		}

		if (m->k2 == 1)
		{
			m->OutStolb(ofst);

			return true;
		}

		if (m->k2 == 2)
		{
			m->OutOdnMas(ofst);

			return true;
		}
	}

	void container::Out(ofstream& ofst) // Вывод содержимого контейнера
	{
		ofst << "Container contains " << size << " elements. " << endl;

		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->OutputNode(ofst);
			curNode->SummaNode(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	void container::OutSquare(ofstream& ofst) 
	{
		ofst << "Container contains " << size << " elements. " << endl;
		ofst << "Only square." << endl; 

		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->SummaNode(ofst);
			curNode->m->OutSquare(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	bool matr::Compare(matr* other)
	{
		return Summa() < other->Summa();
	}

	void container::Sort()
	{
		node* left = head;
		node* right = head->next;
		node* temp = new node;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (left->m->Compare(right->m))
				{
					temp->m = left->m;
					left->m = right->m;
					right->m = temp->m;
				}
				right = right->next;
			}

			left = left->next;
			right = left->next;
		}
	}

	void matr::OutSquare(ofstream& ofst)
	{
		ofst << endl; // пустая строка 
	}

	container::container() // Инициализация контейнера
	{
		size = 0;
		head = NULL;
	}

	void container::Clear()
	{
		node* curNode;
		curNode = head;

		while (curNode != NULL)
		{
			node* temp = curNode->next;
			delete curNode;
			curNode = temp;
		}

		head = NULL;
		size = 0;
	}

	container::~container() // Очистка контейнера от элементов
	{
		Clear();
	}

	node* container::get_node(int index)
	{
		node* retNode = head;

		for (int i = 0; i < index; i++)
		{
			retNode = retNode->next;
		}

		return retNode;
	}

	// Вызов мультиметода для элементов контейнера 
	void container::Multimethod(ofstream& ofst)
	{
		ofst << "\nMultimethod." << endl;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				get_node(i)->m->Multimethod(get_node(j)->m, ofst);
				get_node(i)->OutputNode(ofst);
				get_node(j)->OutputNode(ofst);
			}
		}
	}
} // end simple_shapes namespace