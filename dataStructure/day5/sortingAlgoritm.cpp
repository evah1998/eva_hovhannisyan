#include <iostream>

using namespace std;

void Print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int num1, int num2) {
    int temp;
    temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
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

int GetPivotIndex (int* arr, int left, int right) {
    int pivotIndex = left - 1;
    for (int i = left; i <= right; ++i) {
        if (arr[i] < arr[right]) {
            ++pivotIndex;
            swap(arr, i, pivotIndex);
        }
    }
    ++pivotIndex;
    swap(arr, pivotIndex, right);
    return pivotIndex;
}

void QuickSort (int* arr, int left, int right) {
    if (left < right) {
        int pivotIndex = GetPivotIndex(arr, left, right);
        QuickSort (arr, left, pivotIndex - 1);
        QuickSort (arr, pivotIndex + 1, right);
    }
}

int main() {
    int size = 10000;
    srand(time(0));
    int arr[size];
    int arrCopy[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
    Print(arr, size);

    for (int i = 0; i < size; ++i) {
        arrCopy[i] = arr[i];
    }
    cout << "copy\n";
    Print(arr, size);

    int left = 0;
    int right = size - 1;
    clock_t start = clock();
    MergeSort(arr, left, right);
    clock_t end = clock();
    double time1 = (double) (end-start) / CLOCKS_PER_SEC * 10000;
    cout << "Merge Sorting\n";
    Print(arr, size);

    start = clock();
    QuickSort (arrCopy, left, right);
    end = clock();
    double time2 = (double) (end-start) / CLOCKS_PER_SEC * 10000;
    cout << "Quick Sorting\n";
    Print(arr, size);
    cout << "Time after merge sorting = " << time1 << endl;
    cout << "Time after quick sorting = " << time2 << endl;

    return 0;
}