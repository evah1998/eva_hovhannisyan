#include <iostream>

using namespace std;

int size = 10000;

void Print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int* arr, int left, int middle, int right) {
    int i;
    int j;
    int arrLeft[middle - left + 1];
    for (i = 0; i < middle - left + 1; ++i) {
        arrLeft[i] = arr[left + i];
    }

    int arrRight[right - middle];
    for (j = 0; j < right - middle; ++j) {
        arrRight[j] = arr[middle + 1 + j];
    }

    int k = left;
    i = 0;
    j = 0;
    while (i < middle - left + 1 && j < right - middle) {
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            ++i;
        } else {
            arr[k] = arrRight[j];
            ++j;
        }
        ++k;
    }

    while (i < middle - left + 1) {
        arr[k] = arrLeft[i];
        ++i;
        ++k;
    }

    while (j < right - middle) {
        arr[k] = arrRight[j];
        ++j;
        ++k;
    }
}

void MergeSort(int* arr, int left, int right) {
    int middle;
    if (left < right) {
        middle = left + (right - left) / 2;
        MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);
        Merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(0));
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
    Print(arr, size);

    int left = 0;
    int right = size - 1;
    clock_t start = clock();
    MergeSort(arr, left, right);
    clock_t end = clock();
    double time1 = (double) (end-start) / CLOCKS_PER_SEC;
    Print(arr, size);
    cout << "Time after merge sorting = " << time1 << endl;

    return 0;
}