#include "container_atd.h"
#include <iostream>
using namespace std;

namespace simple_matrix
{
	node::~node() {}

	bool node::AddNode(ifstream& ifst)
	{
		m = matr::In(ifst);

		if ((m == NULL) or (m == 0))
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

			else
				break;
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

	void container::Out(ofstream& ofst) // ����� ����������� ����������
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