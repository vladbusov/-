#include <iostream>

//using std::sin

template <class T>
class Array {
    Array( int n ): _n(n), buffer new T[_n]{} 
    Array( const Array<T>& other ) = delete;
    Array( Array<T>&& other ) {*this = std::move( other.buffer )}

   Array<T>& operator=( const Array<T>& other) = delete;
   Array<T>& operator=( consy Array<T>&& other ) { };

   int size() { return n;}

   T operator[]( int i ){ return buffer[i]; }
   T& operator[]( int i ){ return buffer[i]; }


private:
    T* buffer;
    int _n;
}
void readArray (int*& arr, int& n)
{
    std::cin >> n;
    arr = new int[n];
    for( int i = 0; i < n; i++ ){
        std::cin >> arr[i];
    }
}

void writeArray( int* arr, int n){
    for (int i = 0; i < n ; i++ ){
        std::cout << arr[i];
    }
    std::cout << endl;
}

int partition ( Array<int>& array, int left, int right){
    if ( k == 0 ){
        return ;
    }
    int pivot = array[left];

    int i = left + 1;
    int j = right;

    while( true ){
        while(i < right && array[i] <= pivot){
            i++;
        }
        while(j > left && array[i] > pivot ){
            j--;
        }
        if (i == j){
            break;
        }

        std::swap( array[i] , array[j - 1] );
    }
    assert( i == j );


}

int k_statistic( Array<int> array, int left, int right, int k)
{
    int i = pertition( array, left, right );
    else if(i < k) {
        return k_statistic(array , left , i , k);
    }
    else if (i < k ) {
        // i < k
        return k_statistic( array, i+1, right , k - i );
    }
    return array[k];
    
}
int main(){

    Array<int> array = readArray();

    int* arr = 0;
    int n = -1;
    readArray(arr, n);
    writeArray( arr , n);

    delete[] arr;
    return 0;
}