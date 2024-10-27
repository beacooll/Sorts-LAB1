#include "Sorts.h"
#include <fstream>

int main()
{
    int N = 100001;
    int step = 1000;
    std::ofstream f1("reverse.txt"), f2("random.txt"), f3("90%sorted.txt"), f4("sorted.txt");
   
    
    for (int i = 0; i < N; i += step) {
        int* A = new int[i];
        int sum = 0;
        for (int c = 0; c < 10; c++) {
            for (int j = 0; j < i; j++) {
                A[j] = rand();
            }
            heapSort(A, i);
            reverse(A, i);
            auto start = std::chrono::high_resolution_clock::now();
            hibbardSort(A, i);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            sum += duration.count();
        }
        sum /= 10;
        std::cout << "Function execution time: " << sum << std::endl;
        f1 << i << " " << sum << std::endl;
        delete[]A;
        }
    for (int i = 0; i < N; i += step) {
        int* A = new int[i];
        int sum = 0;
        for (int c = 0; c < 10; c++) {
            for (int j = 0; j < i; j++) {
                A[j] = rand();
            }
            auto start = std::chrono::high_resolution_clock::now();
            hibbardSort(A, i);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            sum += duration.count();
        }
        sum /= 10;
        std::cout << "Function execution time: " << sum << std::endl;
        f2 << i << " " << sum << std::endl;
        delete[]A;
    }
    for (int i = 0; i < N; i += step) {
        int* A = new int[i];
        
        int sum = 0;
        for (int c = 0; c < 10; c++) {
            for (int j = 0; j < i; j++) {
                A[j] = rand();
            }
            heapSort(A, i - i / 10);
            auto start = std::chrono::high_resolution_clock::now();
            hibbardSort(A, i);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            sum += duration.count();
        }
        sum /= 10;
        std::cout << "Function execution time: " << sum << std::endl;
        f3 << i << " " << sum << std::endl;
        delete[]A;
    }
    for (int i = 0; i < N; i += step) {
        int* A = new int[i];
        
        int sum = 0;
        for (int c = 0; c < 10; c++) {
            for (int j = 0; j < i; j++) {
                A[j] = rand();
            }
            heapSort(A, i);
            auto start = std::chrono::high_resolution_clock::now();
            hibbardSort(A, i);
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            sum += duration.count();
        }
        sum /= 10;
        std::cout << "Function execution time: " << sum << std::endl;
        f4 << i << " " << sum << std::endl;
        delete[]A;
    }
    return 0;
}
