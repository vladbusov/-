#include <iostream>
#include <fstream>
using namespace std;


int main()
{

    int n;
    int div;

    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");

    cin >> n;
    int TestNum;
    if (n > 0){
        TestNum = n;
    }else{
        TestNum = -n;
        n = -n;
    }

    int *a = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    a[i] = i;

    for (int p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {   
            if (TestNum >= a[p]){
                div = a[p];
                while (TestNum % div == 0)
                {   
                    if (TestNum/div != 1){
                        cout << div << " ";
                        TestNum = TestNum / div;
                    }else{
                        cout << div;
                        TestNum = TestNum / div;
                    }
                }
            }

            for (int j = p*p; j < n + 1; j += p)
                a[j] = 0;
        }
    }
    infile.close();
    outfile.close();
    delete[] a;
    return 0;
}

