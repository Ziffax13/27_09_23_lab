#include <iostream>
using namespace std;


struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();
    int Find(char);

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
    int GetCount();

    void InsertPos(char, int);
};

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}

void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
    Count++;
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

int List::Find(char c)
{
    int i = 1;
    Element* temp = Head;
    while (true) {
        if (temp->data == c)
        {
            return i;
        }
        i++;
        temp = temp->Next;
    }
    return NULL;
}

void List::InsertPos(char d, int j)
{
    int i = j;
    if (i == this->Count)
    {
        this->Add(d);
        return;
    }
    Element* temp = Head;
    while (i > 3) {
        temp = temp->Next;
        i--;
    }
    Element* ins = new Element;
    ins->data = d;
    ins->Next = temp->Next;
    temp->Next = ins;
    Count++;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}

// Тестовый пример
void main()
{
    // Создаем объект класса List
    List lst;

    // Тестовая строка
    char s[] = "Hello, World !!!\n";
    // Выводим строку
    cout << s << "\n\n";
    // Определяем длину строки
    int len = strlen(s);
    // Загоняем строку в список
    for (int i = 0; i < len; i++)
        lst.Add(s[i]);
    // Распечатываем содержимое списка
    lst.Print();
    lst.InsertPos('c', 6);
    lst.Print();
    cout << lst.Find('H');
}
