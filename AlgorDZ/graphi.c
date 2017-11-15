#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = 0;
    FILE* graph = fopen("graph.dot","w");
    if (graph == NULL){
        printf("Не получается открыть файл!\n");
        return 0;
    }
    printf("Какой вид графа вам требуется?\n1. Неориентированный \n2.Ориентированный\n");
    c = getchar();
    switch (c){
        case 49:
        fputs("graph graphname { ", graph);
        break;
        case 50:
        fputs("digraph graphname { ", graph);
        break;
        default:

        printf("Некорректный ввод данных!\n");
        return 0;
    }

    printf("Опишите граф следующим образом:\n\t graphA -- graphB (неориентированный);\n\t graphA -> graphB (ориентированный);\n");
    while(c != EOF){
        c = getchar();
        if (c != EOF)
            fputc(c, graph );
    }

    fputs(" }", graph);



    return 0;
}