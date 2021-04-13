// sprawdzanie_czasu_dzialania_algorytmow_sortujacych.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdlib>
#include <time.h >
#include <windows.h>

using namespace std;

void print_array(int array[], int size);
void bubble_sort(int array[], int size);

int main()
{   
    srand(time(NULL));
    clock_t start, stop;
    double czas;

    int size = 50;
    int array_to_sort[50];
    
    for (int i = 0; i < 50; i++) {
        array_to_sort[i] = rand() % 500 + 1;
    }
    /*print_array(array_to_sort, size);
    bubble_sort(array_to_sort, size);
    cout << endl;
    print_array(array_to_sort, size);*/

    
}
void print_array(int array[], int size) {
    cout << endl;
    int counter = 0;
    cout << "Array : [";
    for(int i = 0; i < size; i++){
        if (counter % 10 == 0 && counter > 0) {
            cout << "\n\t";
        }
       
        cout << array[i] << ",\t";
        counter++;
    }
    cout << "]";
}
void bubble_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = size - 1; j >= 1; j--) {
            if (array[j] < array[j-1]) {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}
void bucket_sort(int array[], int size) {
    const int WMIN = 1;
    const int WMAX = 500;
   
    int lw[WMAX - WMIN + 1], i, j;

    for (i = WMIN; i <= WMAX; i++) {
        lw[i - WMIN] = 0;
    }

    for (i = 0; i < size; i++) {
        lw[array[i] - WMIN]++;
    }

    j = 0;
    for (i = WMIN; i <= WMAX; i++) {
        while (lw[i - WMIN]--) array[j++] = i;
    }
}
