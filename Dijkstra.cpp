#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    int arrSize{ 0 };
    fstream fin("input.txt");
    int k{ 0 };
    while (fin >> k) {
        ++arrSize;
    }
    fin.seekg(0, ios_base::beg);
    int *previous = new int[arrSize]{ 0 };
    k = 0;
    while (fin >> previous[k]) {
        ++k;
    }
    int *next = new int[arrSize] { 0 };
    fin.close();
    return 0;
}
 