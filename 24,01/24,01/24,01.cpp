#include <iostream>
using namespace std;

struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес концевого элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();
    // Добавление элемента в список
    void Add(char data);
    // Удаление элемента списка
    void Del();
    // Удаление всего списка
    void DelAll();
    // Распечатка содержимого списка
    void Print();
    // Получение количества элементов, находящихся в списке
    int GetCount();
    // Вывод элемента списка по его позиции
    void PrintElementAt(int pos);
};

List::List()
{
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    DelAll();
}

int List::GetCount()
{
    return Count;
}

void List::Add(char data)
{
    Element* temp = new Element;
    temp->data = data;
    temp->Next = NULL;
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        Head = Tail = temp;
    }
    Count++;
}

void List::Del()
{
    if (Head != NULL) {
        Element* temp = Head;
        Head = Head->Next;
        delete temp;
        Count--;
    }
}

void List::DelAll()
{
    while (Head != NULL)
        Del();
}

void List::Print()
{
    Element* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

void List::PrintElementAt(int pos)
{
    if (pos >= 0 && pos < Count) {
        Element* temp = Head;
        for (int i = 0; i < pos; i++) {
            temp = temp->Next;
        }
        cout << "Element at position " << pos << ": " << temp->data << endl;
    }
    else {
        cout << "Invalid position or empty list." << endl;
    }
}

int main()
{
    List lst;
    char s[] = "Hello, World !!!";
    cout << s << endl;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    lst.Print();
    lst.PrintElementAt(5); // Вывод элемента на позиции 5
    lst.PrintElementAt(10); // Вывод элемента на позиции 10 (не существует)
    return 0;
}
