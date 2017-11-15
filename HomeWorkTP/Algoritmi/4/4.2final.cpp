/*
АПО13 Бусов Владислав
Реализовать дек с динамическим зацикленным буфером.
Обрабатывать команды push * и pop *.
Формат ввода
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.

a = 1 - push front
a = 2 - pop front
a = 3 - push back
a = 4 - pop back

Если дана команда pop *, то число b - ожидаемое значение.
Если команда pop * вызвана для пустой структуры данных, то ожидается “-1”.
*/

#define BUFFER_SIZE 100
#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>

using namespace std;

void makeNewBuffer(int newSize,vector<int> * v, int tail, int head){
    vector<int> vTmp(newSize);
    for (int i=0; i<= tail; i++)
        vTmp[i] = v->at(i);
    for (int i=head+1; i < v->size(); i++)
        vTmp[i] = v->at(i);
    v->clear();
    v = &vTmp;
}

template <class T>
 class CDeque{
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

    vector<T> buffer;
    int bufferSize;
    unsigned int head;
    unsigned int tail;
private:
    void free();
    void increase();
};


template <class T>
void CDeque<T>::increase()
{
    bufferSize*=2;
    makeNewBuffer(bufferSize, &buffer , tail, head);
}

template <class T>
void CDeque<T>::free()
{
    if (buffer.empty() != 1)
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
    if ( (tail + 1)%bufferSize == head )
        increase();
    buffer[tail] = a;
    tail = (tail+1)%bufferSize;
    cout << "Change tail =" << " " << tail << endl;
}

template <class T>
void CDeque<T>::pushFront( T a )
{
    if ( (tail +1)%bufferSize == head )
        increase();
    head = (head-1)%bufferSize;
    buffer[head] = a;
    cout << "Change head =" << " " << head << endl;
}

template <class T>
T CDeque<T>::popBack()
{
    if (isEmpty() == 1){
        exit(-1);
    }
    T result = buffer[(tail-1)%bufferSize];
    tail = (tail-1)%bufferSize;
    return result;
}

template <class T>
T CDeque<T>::popFront()
{   
    if (isEmpty() == 1){
        exit(-1);
    }
    T result = buffer[head];
    head = (head + 1)%bufferSize;
    return result;
}

template <class T>
int CDeque<T>::checkCapacity(){
    return bufferSize-(tail-head);
}

void closeFiles(ofstream* f1,ifstream* f2){
    if (f1->is_open())
        f1->close();
    if (f2->is_open())
        f2->close();
}


int main(){
    ofstream outFile;
    ifstream inFile;
    outFile.open("output.txt");
    inFile.open("input.txt");
    
    int action;
    int data;
    int numOfAct;

    CDeque<int> test;

    inFile >> numOfAct;

    for (int i = 0; i < numOfAct ; i++){
        int act;
        inFile >> act;
        int num;
        inFile >> num;

        switch(act){
            case 1:
            test.pushFront(num);
            break;
            case 2:
            if (test.popFront() != num){
                outFile << "NO";
                closeFiles(&outFile,&inFile);
                return 0;
            }
            break;
            case 3:
            test.pushBack(num);
            break;
            case 4:
            int tmp = test.popBack();
            cout << "tmp = " << tmp << " ;" << endl;
            if (tmp != num){
                outFile << "NO";
                closeFiles(&outFile,&inFile);
                return 0;
            }
            break;
        }
        cout << "Now vector = {" ;
        for (int i = test.head; i < test.tail; i++){
            cout << test.buffer[i] << ", ";
        }
        cout << "} head = " << test.head << "; tail = " << test.tail << ";" << endl;
    }
    outFile << "YES";
    closeFiles(&outFile,&inFile);
    return 0;
}