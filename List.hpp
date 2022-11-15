#pragma once
#include <iostream>

namespace Compiler
{

    using namespace std;

    template <typename t>
    struct Node
    {
        t NodeValue;
        Node *Next, *Prev;

        Node(t value) { NodeValue = value; }
    };

    template <typename t>
    class List_Iterator
    {
    public:
        typedef List_Iterator<t> self;
        typedef Node<t> node;
        using ValueType = t;
        using Pointer = ValueType *;
        using Reference = ValueType &;

        List_Iterator(node *x) : Nodeptr(x) {}

        Reference operator*() { return Nodeptr->NodeValue; }

        Pointer operator->() { return Nodeptr->NodeValue; }

        self &operator++()
        {
            Nodeptr = Nodeptr->Next;
            return *this;
        }

        self operator++(int)
        {
            self tmp = *this;
            Nodeptr = Nodeptr->Next;
            return tmp;
        }

        self &operator--()
        {
            Nodeptr = Nodeptr->Prev;
            return *this;
        }

        self operator--(int)
        {
            self tmp = *this;
            Nodeptr = Nodeptr->Prev;
            return tmp;
        }

        friend bool
        operator==(const self &x, const self &y) { return x.Nodeptr == y.Nodeptr; }

        friend bool
        operator!=(const self &x, const self &y) { return x.Nodeptr != y.Nodeptr; }

        node *Nodeptr;
    };

    template <typename t>
    class DLL
    {
    private:
        Node<t> *Head, *Tail;
        Node<t> *GetHead() { return Head; }
        Node<t> *GetTail() { return Tail; }
        void AddHead(t value);
        void AddTail(t value);
        void RemoveHead();
        void RemoveTail();
        void clear();

    public:
        using valueType = t;
        using iterator = List_Iterator<valueType>;
        DLL()
        {
            Head = nullptr;
            Tail = nullptr;
        }
        ~DLL() { clear(); }
        bool isEmpty()
        {
            if (Head == nullptr && Tail == nullptr)
                return true;
            else
                return false;
        }
        void pop_front();
        void pop_back();
        void push_front(t value);
        void push_back(t value);
        int size();
        Node<t> *at(int index);

        iterator begin() { return iterator(Head); }
        iterator end() { return iterator(Tail->Next); }
    };

    template <class t>
    void DLL<t>::push_back(t value)
    {
        AddTail(value);
    }

    template <class t>
    void DLL<t>::push_front(t value)
    {
        AddHead(value);
    }

    template <class t>
    void DLL<t>::pop_back()
    {
        RemoveTail();
    }

    template <class t>
    void DLL<t>::pop_front()
    {
        RemoveHead();
    }

    template <class t>
    void DLL<t>::AddHead(t parameter)
    {
        Node<t> *Link = new Node<t>(parameter);
        if (isEmpty())
        {
            Head = Link;
            Tail = Link;
        }
        else
        {
            Link->Next = Head;
            Link->Prev = nullptr;
            Head->Prev = Link;
            Head = Link;
        }
    }

    template <class t>
    void DLL<t>::AddTail(t parameter)
    {
        Node<t> *Link = new Node<t>(parameter);
        if (isEmpty())
        {
            Head = Link;
            Tail = Link;
        }
        else
        {
            Link->Prev = Tail;
            Link->Next = nullptr;
            Tail->Next = Link;
            Tail = Link;
        }
    }

    template <class t>
    void DLL<t>::RemoveHead()
    {
        Node<t> *Temp = GetHead();
        if (Temp == nullptr)
            ;
        else
        {
            if (Head == Tail)
            {
                delete Temp;
                Head = nullptr;
                Tail = nullptr;
            }
            else
            {
                Temp->Next->Prev = nullptr;
                Head = Temp->Next;
                Temp->Next = nullptr;
                delete Temp;
            }
        }
    }

    template <class t>
    void DLL<t>::RemoveTail()
    {
        Node<t> *Temp = GetTail();
        if (Temp == nullptr)
            ;
        else
        {
            if (Head == Tail)
            {
                delete Temp;
                Head = nullptr;
                Tail = nullptr;
            }
            else
            {
                Temp->Prev->Next = nullptr;
                Tail = Tail->Prev;
                Temp->Prev = nullptr;
                delete Temp;
            }
        }
    }

    template <class t>
    void DLL<t>::clear()
    {
        while (!isEmpty())
        {
            RemoveHead();
        }
        cout << "Done" << endl;
    }

    template <class t>
    int DLL<t>::size()
    {
        Node<t> *Link = Head;
        int size = 0;
        while (Link != Tail)
        {
            size++;
            Link = Link->Next;
        }
        return size;
    }

    template <class t>
    Node<t> *DLL<t>::at(int index)
    {
        int curr = 0;
        Node<t> *Link = Head;
        while (curr != index)
        {
            Link = Link->Next;
            curr++;
        }
        return Link;
    }
}
