
/*
Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
n, m ≤ 100000.
Указание. Обходите массив B от конца к началу.
*/


#include <fstream>
#include <cassert>
using namespace std;

int CheckIndexes(long int sizeOfA,long int sizeOfB,long int* A, long int* B, long int k){
    // счетчик
    long int cnt = 0;
    int startInd = 0;
   
    for (long int i = sizeOfB-1; i >=0 ; i--){
        for (int j = startInd; j < sizeOfA; j++ ){
            if ((A[j]+B[i]) == k){
                cnt++;
            }else if ((A[j]+B[i]) > k){
                startInd = j;
                break;
            }
        }
    }
    return cnt;
}

int main(){

    ofstream outFile;
    ifstream inFile;
    outFile.open("output.txt");
    inFile.open("input.txt");

    // ввод А
    long int sizeOfA;
    inFile >> sizeOfA;

    assert(sizeOfA >= 0);
    if (sizeOfA == 0){
        outFile << 0;
        outFile.close();
        inFile.close();
        return 0;
    }

    long int* A = new long int[sizeOfA];
    for (long int i=0;i< sizeOfA;i++){
        inFile >> A[i];
    }

    // ввод B
    long int sizeOfB;
    inFile >> sizeOfB;

    assert(sizeOfB >= 0);
    if (sizeOfA == 0){
        outFile << 0;
        outFile.close();
        inFile.close();
        delete[] A;
        return 0;
    }

    long int* B = new long int[sizeOfB];
    for (long int i=0;i< sizeOfB;i++){
        inFile >> B[i];
    }
        
    // ввод K
    long int k;
    inFile >> k;

    outFile << CheckIndexes(sizeOfA,sizeOfB,A,B,k) << endl; // вывод

    outFile.close();
    inFile.close();
    delete[] A;
    delete[] B;
    return 0;
}