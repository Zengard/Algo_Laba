// Laba3-QuickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>
#include "Header.h"

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> rand(1, 100);
    generator.seed(time(NULL));

    std::ofstream saveTime("time.txt");

    //saveTime << "insertionSort\n";

    //auto startTime = std::chrono::high_resolution_clock::now();


    for (int size = 5; size <= 100; size++) {

        std::chrono::nanoseconds insertTime = std::chrono::nanoseconds(0);
        std::chrono::nanoseconds quickSortTime = std::chrono::nanoseconds(0);

        int* arrInsert = new int[size];
        int* arrQuickSort = new int[size];

        for (int j = 0; j < 100; j++) {

            for (int i = size - 1, k = 1; i >= 0; i--, k++) {
                arrInsert[i] = k;
            }

            for (int i = 0; i < size; i++) {
                arrQuickSort[i] = rand(generator);
            }



            auto start = std::chrono::high_resolution_clock::now();
             insertionSort(arrInsert, arrInsert + size - 1, [](int a, int b) {return a < b; });
             auto end = std::chrono::high_resolution_clock::now();

             insertTime = (end - start);

             start = std::chrono::high_resolution_clock::now();
             quickSort(arrQuickSort, arrQuickSort + size - 1, [](int a, int b) {return a < b; });
             end = std::chrono::high_resolution_clock::now();

             quickSortTime = (end - start);


        }
      
        insertTime /= 10000;
        quickSortTime /= 10000;

        if (saveTime.is_open()) {
            saveTime << " Size: " << size << "; Insert: " << insertTime.count() << "; QuickSort: " << quickSortTime.count()<<std::endl;
        }

        delete[] arrInsert;
        delete[] arrQuickSort;

    }
    
}

