#include <iostream>
#include <fstream>

//Поменять значения 2-х элементов в массиве
void swap(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//Перевернуть "хвост"
void tailFlip(char arr[], int i, int size) {
    //Массив-маска
    char *arr2 = new char[size]{ 0 };
    for (int k{ size - 1 }, m{ i }; k >= i ;++m, --k) {
        arr2[m] = arr[k];
    }
    //Наложение массива-маски
    for (int k{ i }; k < size; ++k) {
        arr[k] = arr2[k];
    }
    delete[] arr2;
}
int Dijkstra(char perm[], int size){
    for (int i{ size - 2 }; i >= 0; --i) {
        if (perm[i] < perm[i + 1]) {
            int tailStart{ i + 1 };
            int minIndex{ tailStart };
            for (int j{ size - 1 }; j >= tailStart; --j) {
                if (perm[i] < perm[j] && perm[minIndex] > perm[j]) {
                    minIndex = j;
                }
            }
            swap(perm, i, minIndex);
            tailFlip(perm, tailStart, size);
            return 1;
        }
    }
return 0;
}

//Посчитать количество чисел в файле
int countNumbersInFile(std::string file) {
    using namespace std;
    int count{ 0 };
    ifstream fin(file);
    char temp{ 0 };
    while (fin >> temp) {
        ++count;
    }
    fin.clear();
    return count;
}

void readFromFileToArr(std::string file, char* arr) {
    int temp{ 0 };
    std::ifstream fin("input.txt");
    while (fin >> arr[temp]) { //Считывание перестановки
        ++temp;
    }
    fin.close();
}
int main() {
    using namespace std;
    //Размер массива
    int arrSize{ countNumbersInFile("input.txt") };
    //Перестановка
    char *permutation = new char[arrSize]{ ' ' };
    //Считывание данных в массив
    readFromFileToArr("input.txt", permutation);
    //Открываем файл и очищаем
    ofstream fout("output.txt", std::ofstream::out | std::ofstream::trunc);
    //Сам алгоритм
    while (Dijkstra(permutation, arrSize)) {
        //Запись в файл
        for (int i{ 0 }; i < arrSize; ++i) {
            fout << permutation[i] << " ";
        }
        fout << '\n';
    }
    delete[] permutation;
    return 0;
}
 