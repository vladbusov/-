/*
3_1. Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
 Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента 
 массива A, равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, 
 выведите n. Время работы поиска k для каждого элемента B[i]: O(log(k)).
n, m ≤ 10000.
*/
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

void closeFiles(ofstream* f1,ifstream* f2){
    if (f1->is_open())
        f1->close();
    if (f2->is_open())
        f2->close();
}

int binSearch(long int* array,long int left,long int right,long int value)
{
	int first = left;
	int last = right;
	int mid;
	while( first < last ) 
	{
		mid = (first + last) / 2;
		if(value <= array[mid])
			last = mid;
		else
			first = mid + 1;
	}
	return value <= array[last] ? last : right;
}

void searchLimit(long int* array,long int size,long int value,long int* min,long int* max)
{
	int i = 0;
	while(array[1 << i] < value && (1 << i) < size) 
	{
		i++;
	}
	*min = (i == 0) ? 0 : 1 << (i - 1);
	*max = ((1 << i) < size)? 1 << i : size;
}

int main(){

    ofstream outFile;
    ifstream inFile;
    outFile.open("output.txt");
    inFile.open("input.txt");

    long int sizeOfA;
    inFile >> sizeOfA;


    long int sizeOfB;
    inFile >> sizeOfB;

    if (sizeOfA <= 0 || sizeOfB <= 0){
        closeFiles(&outFile,&inFile);
        return 0;
    }

    long int* A = new long int[sizeOfA];

    if (A == NULL){
        closeFiles(&outFile,&inFile);
        return 0;
    }

    for (long int i=0;i< sizeOfA;i++){
        inFile >> A[i];
    }


    long int* B = new long int[sizeOfB];

    if (B == NULL){
        delete[] A;
        closeFiles(&outFile,&inFile);
        return 0;
    }

    for (long int i=0;i< sizeOfB;i++){
        inFile >> B[i];
    }


    long int indexMin;
    long int indexMax;

	for(int i = 0; i < sizeOfB; i++)
	{
		indexMin = 0; 
		indexMax = sizeOfA; 
		searchLimit(A, sizeOfA, B[i], &indexMin, &indexMax);
		outFile << binSearch(A, indexMin, indexMax, B[i]) << " ";
	}
    

    closeFiles(&outFile,&inFile);
    delete[] A;
    delete[] B;
    return 0;
}