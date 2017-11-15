#include <iostream>
#include <cassert>
#include <vector>

#define BUFFER_SIZE 100

using namespace std;

/*
Если new не может выделить память в куче, то он передаст (throw) исключение типа std::bad_alloc
*/

template <class T>
сlass CDeque {
public:
    CDeque();
    ~CDeque() { free(); }

    CDeque<T>& operator=( const CDeque<T>& other ) = delete; // не принимаем lvalue ссылки
    CDeque<T>& operator=( CDeque<T>&& other ); // перемещяем rvalue ссылки

    CDeque( const CDeque<T>& other ) = delete; // lvalue нельзя украсть :(
    CDeque( CDeque<T>&& other ) { *this = std::forward<CDeque>( other ); } // перемещающий конструктор

    void pushBack( T a );
    void pushFront( T a );

    T popBack();
    T popFront();

    bool isEmpty() const { return head == tail; }

    int checkCapacity();
private:
    vector<T> buffer;
    int bufferSize;
    int head;
    int tail;

    void free();
    void increase();
    void decrease();
}

template <class T>
void CDeque<T>::increase()
{
    bufferSize*=2;
    buffer.resize( bufferSize );
}

template <class T>
void CDeque<T>::decrease()
{
    bufferSize/=2;
    buffer.resize( bufferSize );
}

template <class T>
void CDeque<T>::free()
{
    buffer.clear();
}

template <class T>
CDeque<T>::CDeque():
    bufferSize( BUFFER_SIZE ),
    head(0),
    tail(0)
{
    buffer.reserve( bufferSize );
}

template <class T>
void CDeque<T>::pushBack( T a )
{
    if ( tail + 1 >= bufferSize )
        increase();
    buffer[tail] = a;
    tail++;
}

template <class T>
void CDeque<T>::pushFront( T a )
{
    if ( tail +1 >= bufferSize )
        increase();
    buffer.insert( head, a );
    tail++;
}

template <class T>
T CDeque<T>::popBack()
{
    assert(isEmpty() == 0);
    T result = buffer[tail];
    tail--;
    return result;
}

template <class T>
T CDeque<T>::popFront()
{
    assert(isEmpty() == 0);
    T result = buffer[head];
    head++;
    return result;
}

template <class T>
int CDeque<T>::checkCapacity(){
    return bufferSize-(tail-head);
}
