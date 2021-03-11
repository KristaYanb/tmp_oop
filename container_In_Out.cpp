#include "container_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	node::~node() {}

	bool node::add_node(ifstream& ifst)
	{
		m = matr::In(ifst);
		if (m == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void container::In(ifstream& ifst)
	{
		while (!ifst.eof())
		{
			node* tmpNode = new node;
			if (tmpNode->add_node(ifst)) 
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

	int node::summa_node(ofstream& ofst)
	{
		return m->Summa();;
	}

	bool node::output_node(ofstream& ofst)
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

	void container::Out(ofstream& ofst) // ����� ����������� ����������
	{
		ofst << "Container contains " << size << " elements. " << endl;
		node* curNode = head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			curNode->output_node(ofst);
			curNode->summa_node(ofst);
			//ofst << "Summa = " << curNode->summa_node(ofst) << endl;
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
			curNode->summa_node(ofst);
			//ofst << "Summa = " << curNode->summa_node(ofst) << endl;
			curNode->m->OutSquare(ofst);
			curNode = curNode->next;
			i++;
		}
	}

	bool matr::compare(matr* other)
	{
		return Summa() < other->Summa();
	}

	void container::sort()
	{
		node* left = head;
		node* right = head->next;

		node* temp = new node;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (left->m->compare(right->m))
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
		ofst << endl; // ������ ������ 
	}

	container::container() // ������������� ����������
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

	container::~container() // ������� ���������� �� ���������
	{
		Clear();
	}

} // end simple_shapes namespace