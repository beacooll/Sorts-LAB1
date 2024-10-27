#pragma once
#include <random>
#include <iostream>
#include <time.h>
#include <chrono>

int getMin(int A[], int N, int i);
void selectionSort(int A[], int N);
void insertionSort(int A[], int N);
void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);
int partition(int A[], int left, int right);
void quickSort(int A[], int left, int right);
void shellSort(int A[], int N);
void bubbleSort(int A[], int N);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
bool compareArray(int A[], int B[], int N);
void reverse(int A[], int N);

void hibbardSort(int A[], int N);
void prattSequence(int N, int gaps[], int& size);
void prattSort(int A[], int N);