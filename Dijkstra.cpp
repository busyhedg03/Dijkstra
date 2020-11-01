﻿#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    //Размер массивов
    int arrSize{ 0 };
    fstream fin("input.txt");
    //Временная переменная
    int k{ 0 }; 
    while (fin >> k) {
        ++arrSize;
    }
    //Возврат указателя на начало
    fin.clear();
    fin.seekg(0, ios_base::beg);
    //Предыдущая перестановка
    int *previous = new int[arrSize]{ 0 };
    k = 0;
    while (fin >> previous[k]) { //Считывание перестановки
        ++k;
    }
    //Следующая перестановка
    int *next = new int[arrSize] { 0 };
    fin.close();
    return 0;
}
 