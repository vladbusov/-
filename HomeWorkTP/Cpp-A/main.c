#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#define DIV "<div>"
#define endDIV "</div>"


typedef struct WordArray{
    char ** _data;
    int _size;
} WordArray; 

typedef struct ByteMap{
    char * _data;
    int _size;
} ByteMap;

typedef struct Buffer{
    char * _data;
    int _size;
} Buff;

WordArray* CreateWA(){
    WordArray* A= (WordArray*)calloc(1,sizeof(WordArray));
    assert(A  != 0);
    A->_size = 0;
}

ByteMap* CreateBM(){
    ByteMap* A = (ByteMap*)calloc(1,sizeof(ByteMap));
    A->_size = 0;
}

void PushWA(WordArray* A,char* string){
    A->_data = (char **)realloc(A->_data,(++A->_size)*sizeof(char*));
    A->_data[A->_size - 1] = string;
}

void PushBM(ByteMap* A,char ch){
    A->_data = (char *)realloc(A->_data,(++A->_size)*sizeof(char));
    A->_data[A->_size - 1] = ch;
}

Buff* ReadBlock(){
    Buff* A = (Buff*)calloc(1,sizeof(Buff));
    A->_size = 100;
    A->_data = (char*)calloc(100,sizeof(char));
    if (read(STDIN_FILENO, A->_data, 100) !=100){
        free(A->_data);
        free(A);
        return NULL;
    }else{
        return A;
    }
}


char PopBuffer(Buff* A){
    char tmp = A->_data[0];
    A->_data = (char*)realloc(A->_data,(--A->_size)*sizeof(char));
    assert(A->_data != 0);
    return tmp;
} 

int CheckBuffer(Buff* A){
    if (A->_size == 0){
        free(A);
        return 0;
    }else{
        return 1;
    }
}

char** div_format(char **s) {
    int close = 0;
    int lvl = 0;

    Buff* buffer = ReadBlock();    
    while(close == 0){

        if (CheckBuffer(buffer)!=1){
            buffer = ReadBlock();
            while(CheckBuffer(buffer)){
            close = sizeof(buffer->_data - strchr(buffer->_data,EOF));
            int div = sizeof(buffer->_data - strstr(buffer->_data,DIV));
            
            }
        }

    }
} 

int main(){
    char** place; 
    div_format(place);
    return 0;
}