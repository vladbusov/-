#include "numbers.h"

int pow(int a, int n){
    int tmp = a;
    if(n == 0)
        return 1;
    for (int i=1; i<n;i++)
        a*=tmp;
    return a;
}

int tobinary(int k){
    if (k == 0)
        return 0;
    int size = 0;
    int tmp = k;
    while(tmp){
        size++;
        tmp/=2;
    }
    int sum=0;
    while(k){
        sum+= (k%2)*pow(10,size--);
        k/=2;
    }
    return sum;
}

void input(Mnoj* A){
    printf("Write down a number of your inputs:\n");
    int n;
    if (scanf("%d", &n) < 1){
        printf("Err\n");
    }else{
    A->_size = n;
    A->_data = (int *)calloc(A->_size, sizeof(int));
    int cnt = 0;
    while(n){
        int i;
        if(scanf("%d",&i) < 1){
                printf("Err\n");
                n--;
                char tmpstr[STR_SIZE];
                scanf("%s",tmpstr);
            }else {
                n--;
                A->_data[cnt++] = tobinary(i);
            }
        
        }
    }
    
}
void output(Mnoj* A){
    for(int i=0;i< A->_size; i++){
        if (A->_data[i] > 0)
        printf("%d\n",A->_data[i]);
    }
}

int checkbin(int k){
    while(k){
        if(k%10 > 1)
            return 0;
        k/=10;
    }
    return 1;
}

Mnoj* startw(){
    Mnoj* a = (Mnoj*)calloc(1,sizeof(Mnoj));
    a->_size = 0;
    a->_data = NULL;
    return a;
}