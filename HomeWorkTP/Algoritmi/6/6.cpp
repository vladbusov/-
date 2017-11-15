/*
Дано N кубиков. Требуется определить каким количеством способов можно 
выстроить из этих кубиков пирамиду.
Формат ввода
На вход подается количество кубиков N.
Формат вывода
Вывести число различных пирамид из N кубиков.
*/

#include <iostream>

using namespace std;

long long ** allocMem(int n)
{
	int size = n/2 -1;
	long long** result = new long long*[size];
	int sizeOfCol = n - 3;
   for(int i = 0; i < size; i++){
	result[i] = new long long[sizeOfCol];
   }
   return result;
}

void freeMem(long long ** memory, int n){
	int size = n/2-1;
   for(int i = 0; i < size; i++)
	   delete[] memory[i];
   delete[] memory;
}

long long highOfPyram(int currentN, int cubes,long long ** cache)
{
   long long sum = 0;
   for(int newLayer = currentN; newLayer <= cubes; newLayer++){
	   int remainCub = cubes - newLayer;
	   if(!remainCub || remainCub == newLayer){
		   sum++;
	   } else {
		   if (remainCub > newLayer)
		   {
			  long long cached = cache[newLayer - 1][remainCub - 2]; // -1 (массив с 0) -1 1 куб сверху
			  if(!cached){
				  cached = highOfPyram(newLayer,remainCub,cache);
				  cache[newLayer - 1][remainCub - 2] = cached;
			  }
			  sum += cached;
		   }
		}
   }
   return sum;

}

long long calHighOfPyram(int n){
   if(!n){
	   return 0;
   }
   long long** cache = allocMem(n);
   long long sum = 1;
   for(int i = 1; i < n; ++i)
	   sum += highOfPyram( i, n-i , cache );
   freeMem(cache,n);
   return sum;
}

int main(){
   int n = 0;
   cin >> n;
   cout << calHighOfPyram(n);
   return 0;
}