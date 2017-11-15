/*


Реализовать дек с динамическим зацикленным буфером.

Обрабатывать команды push * и pop *.
Формат ввода

В первой строке количество команд n. n ≤ 1000000.

Каждая команда задаётся как 2 целых числа: a b.

a = 1 - push front
a = 2 - pop front
a = 3 - push back
a = 4 - pop back

Если дана команда pop *, то число b - ожидаемое значение. Если команда pop * вызвана для пустой структуры данных, то ожидается “-1”.

*/
#include <iostream>
using namespace std;


template <class T>
class CDeque {
    public:
        CDeque();
        ~CDeque(){ delete[] buffer; };

        CDeque<T>& operator=( const CDeque<T>& other ) = delete; // не принимаем lvalue ссылки
        CDeque<T>& operator=( CDeque<T>&& other ); // перемещяем rvalue ссылки
    
        CDeque( const CDeque<T>& other ) = delete; // lvalue нельзя украсть :(
        CDeque( CDeque<T>&& other ) { *this = std::forward<CDeque>( other ); } // перемещающий конструктор

        void pushFront(T value);
        T popFront(T value);
        void pushBack(T value);
        T popBack(T value);
        bool showState();
    private:
        void reallocBuffer();
        bool isEmpty();
        bool state;
        int realsize; 
        int buffersize;
        int tail;
        int head;
        int *buffer;
};
 

template <class T>
CDeque<T>::CDeque() {
    tail = 0;
    head = 0;
    realsize = 0;
    buffersize = 0;
    state = true;
    buffer = 0;
}

template <class T>
void CDeque<T>::reallocBuffer() {
    if (buffersize == 0) {
        buffer = new int [1];
        buffersize = 1;
    }
    else { 
        int *newBuf = new int [buffersize*2];  
        for (int i = 0; i < buffersize; i++) {
            newBuf[i] = buffer[(head + i)%buffersize];
        }
        tail = buffersize-1;
        head = 0;
        buffer = newBuf;
        buffersize *= 2;
    }
}

template <class T>
bool CDeque<T>::isEmpty () {
    return realsize == 0;
}

template <class T>
void CDeque<T>::pushBack (T value) {
    realsize++;
    if (realsize > buffersize) {
        reallocBuffer();
    }
    tail = (tail + 1) % buffersize;
    buffer[tail] = value;
}

template <class T>
T CDeque<T>::popBack(T value) {
    T result;
    if (!isEmpty()) {
        result = buffer[tail];
        if (value != result) state = false;
        tail = (buffersize + tail - 1)%buffersize;
        realsize--;
    }
    else {
        if (value != -1) state = false;
    }
    return result;
}

template <class T>
T CDeque<T>::popFront(T value) {
    T result;
    if (!isEmpty()) {
        result = buffer[head];
        if (value != result) state = false;
        head = (head + 1) % buffersize;
        realsize--;
    }
    else {
        if (value != -1) state = false;
    }
    return result;
}

template <class T>
void CDeque<T>::pushFront (T value) {
    realsize++;
    if (realsize > buffersize) {
        reallocBuffer();
    }
    head = (buffersize + head - 1) % buffersize;
    buffer[head] = value;
}

template <class T>
bool CDeque<T>::showState () {
    return state;
}
 
int main()
{
    int n;
    cin >> n;
    CDeque<int> test;
    for (int i = 0; i < n; i++) {
        int number;
        int value;
        cin >> number;
        cin >> value;
        switch (number) {
            case 1:
                test.pushFront(value);
                break;
            case 2:
                test.popFront(value);
                break;
            case 3:
                test.pushBack(value);
                break;
            case 4:
                test.popBack(value);
                break;
            default:
                break;
        };
    }
    if (test.showState()) 
        cout<<"YES"; 
        else 
        cout<<"NO";
    return 0;
}