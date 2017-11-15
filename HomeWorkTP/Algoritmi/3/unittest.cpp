#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    ifstream infile;
    infile.open("input.txt");
    int sizeOfA = rand()/11;
    int sizeOfB = rand()/11;
    cout << sizeOfA << endl;
    cout << sizeOfB << endl;
    for (int i =0; i < sizeOfB ; i++)
        cout << (rand()/200) << " ";
    cout << endl;
    int k = 0;
    for (int j=0; j < sizeOfA ; j++){
        int randVal = rand()/(k+10);
        while (k >= randVal){
            randVal = rand()/(k+10);
        }
        k = randVal;
        cout << randVal << " ";
    }
    infile.close();
    return 0;
}