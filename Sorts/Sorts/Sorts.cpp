#include "Sorts.h"


int getMin(int A[], int N, int i) {
    int min = A[i];
    int num = i;
    for (int j = i; j <  N; j++) {
        if (min > A[j]) {
            min = A[j]; num = j;
        }
        
    }
    return num;
}
void selectionSort(int A[], int N) {
    for (int i = 0; i < N; i++) {
        int min = getMin(A, N, i);
        std::swap(A[i], A[min]);
    }
}

void insertionSort(int A[],int N) {
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }

    
}

void merge(int A[], int left, int mid, int right)
{
    int N1 = mid - left + 1, N2 = right - mid;
    int* B = new int[N1];
    int* C = new int[N2];

    for (int i = 0; i < N1; i++)
        B[i] = A[left + i];
    for (int i = 0; i < N2; i++)
        C[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while ((i < N1) && (j < N2)) {
        if (B[i] < C[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while (i < N1) {
        A[k] = B[i];
        i++;
        k++;
    }

    while (j < N2) {
        A[k] = C[j];
        j++;
        k++;
    }
    delete[]B; delete[]C;
}

void mergeSort(int A[], int left, int right) 
{
    int mid = (right + left)/2;
    if (left < right) {

        mergeSort(A, left, mid);
        
        mergeSort(A, mid + 1, right);
        
        merge(A, left, mid, right);
        
    }
}

int partition(int A[], int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = A[mid]; 
    std::swap(A[mid], A[right]); 

    int i = left - 1; 

    for (int j = left; j < right; j++) {
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]); 
        }
    }
    std::swap(A[i + 1], A[right]); 
    return i + 1; 
}

void quickSort(int A[], int left, int right) {
    if (left < right) {
        int p = partition(A, left, right); 
        quickSort(A, left, p - 1); 
        quickSort(A, p + 1, right); 
    }
}

void shellSort(int A[], int N)
{  
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
             int temp = A[i], j;
             for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];
             A[j] = temp;
        }
    }  
}





void hibbardSort(int A[], int N) {
    int gap = 1;
    while (gap < N / 2) {
        gap = 2 * gap + 1;
    }
    while (gap >= 1) {
        for (int i = gap; i < N; i++) {
            int temp = A[i];
            int j = i;

            while (j >= gap && A[j - gap] > temp) {
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = temp;
        }
        gap /= 2;
    }
}

void prattSequence(int N, int gaps[], int &size) 
{

        int i = 0, j = 0;
        while (true) {
            int value = (1 << i) * (1 << (j + 1));
            if (value > N) {
                break;
            }
            gaps[size++] = value;
            if (i < j) {
                j++;
            }
            else {
                i++;
            }
        }
}


void prattSort(int A[], int N) {
    int gaps[100];
    int size = 0;
    
    prattSequence(N, gaps, size);
    

    for (int k = 0; k < size; k++) {
        int gap = gaps[k];
        for (int i = gap; i < N; i++) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}

void bubbleSort(int A[], int N) {
    
    bool swapped;

    for (int i = 0; i < N - 1; i++) {
        swapped = false;
        
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                swapped = true;
            }

        }
        if (!swapped)
            break;
    }
    
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}



bool compareArray(int A[], int B[], int N) {
    for (int i = 0; i < N; i++) {
        if (A[i]!=B[i])return 0;
    }
    return 1;
}

void reverse(int A[], int N)
{
    for (int i = 0; i < N / 2; i++) {
        std::swap(A[i], A[N - 1 - i]);
    }
}