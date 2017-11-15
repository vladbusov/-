/*
В город N приехал цирк с командой атлетов. Они хотят удивить горожан города N — выстроить из своих тел башню максимальной высоты. Башня — это цепочка атлетов, первый стоит на земле, второй стоит у него на плечах, третий стоит на плечах у второго и т.д. Каждый атлет характеризуется силой si (kg) и массой mi (kg). Сила — это максимальная масса, которую атлет способен держать у себя на плечах. К сожалению ни один из атлетов не умеет программировать, так как всю жизнь они занимались физической подготовкой, и у них не было времени на изучение языков программирования. Помогите им, напишите программу, которая определит максимальную высоту башни, которую они могут составить. Известно, что если атлет тяжелее, то он и сильнее: если mi>mj, то si > sj. Атлеты равной массы могут иметь различную силу.
Формат ввода

Вход содержит только пары целых чисел — массу и силу атлетов. Число атлетов 1 ≤ n ≤ 100000. Масса и сила являются положительными целыми числами меньше, чем 2000000.
Формат вывода

Выход должен содержать натуральное число — максимальную высоту башни.
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void readAndSort(vector<long>* massVec , vector<long>* powerVec){
    long mass = 0;
    long power = 0;

    while(scanf("%ld %ld", &mass, &power) == 2) {
        massVec->push_back(mass);
        powerVec->push_back(power);
    }
    sort(massVec->begin(), massVec->end());
    sort(powerVec->begin(), powerVec->end());
}

long calculHeight(vector<long>* massVec , vector<long>* powerVec){
    long curMass = massVec->at(0);
    long curHeight = 1;

    for(int i = 1; i < massVec->size(); i++) {
        if(powerVec->at(i) >= curMass) {
            curMass += massVec->at(i);
            curHeight++;
        }
    }
    return curHeight;
}

int main() {

    vector<long> massVec;
    vector<long> powerVec;

    readAndSort(&massVec, &powerVec);
    cout << calculHeight(&massVec, &powerVec);
    return 0;
}