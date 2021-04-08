#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "matr_atd.h"

namespace simple_matrix
{
    class node
    {
    public:
        matr* m;
        node* next;
        bool AddNode(ifstream& ifst);
        bool OutputNode(ofstream& ofst);
        int SummaNode(ofstream& ofst);
        ~node();
    };

    struct container
    {
    public:
        int size;
        node* head;
        void In(ifstream& ifst);
        void Out(ofstream& ofst);
        void Sort();    //сортировка
        void OutSquare(ofstream& ofst);
        void Clear();
        container();
        ~container();
    };
} // end simple_matrix namespace
#endif
