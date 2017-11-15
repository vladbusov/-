/*
1_2. Вывести разложение натурального числа n на простые множители. 
Простые множители должны быть упорядочены по возрастанию и разделены пробелами.
2 ≤ n ≤ 106.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, div = 2;
    ofstream outFile;
    ifstream inFile;
    outFile.open("output.txt");
    inFile.open("input.txt");

    inFile >> n;
    while (n > 1)
    {
        while (n % div == 0)
        {
            n = n / div;
            outFile << div << " ";
        }
        div++;
    }
    outFile.close();
    inFile.close();
    return 0;
} 