#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    
    int x;
    Node* Next;
};
class Array
{
    Node* Head, * Tail; 
public:
    Array() :Head(NULL), Tail(NULL) {}; 
    ~Array(); 
    void Push(int x); 
    void Peek();
    void Pop();
    friend ostream& operator << (ostream& stream, const Array& a); 
};
Array::~Array() 
{
    Node* temp = Head; 
    while (temp != 0) 
    {
        temp = Head->Next; 
        delete Head;  
        Head = temp; 
    }
}
void Array::Push(int x)
{
    Node* temp = new Node;
    temp->x = x;
    temp->Next = NULL; 

    if (Head != NULL)
    {
        Tail->Next = temp; 
        Tail = temp;
    }
    else Head = Tail = temp; 
}
ostream& operator << (ostream& stream, const Array& a)
{
    Node* temp = a.Head;
    while (temp != NULL) 
    {
        stream << temp->x << "";
        temp = temp->Next; 
    }
    return stream << endl;
}
void Array::Peek()
{
    cout << Head->x;
}
void Array::Pop()
{
    Head = Head->Next;
}
void main()
{
    Array arr;
    int size, count;
    cout << "Size = ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Count " << i << "/" << size << " = ";
        cin >> count;
        arr.Push(count);
    }
    cout << arr;
    arr.Peek();
    arr.Pop();
    cout << endl;
    cout << arr;
}

