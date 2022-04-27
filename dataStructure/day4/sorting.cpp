#include <iostream>

using namespace std;

const int size = 10000;
int arr[size];
int arrCopy[size];

void Print(int arr[]) {
    for (int i = 0; i < size; ++i) { 
        cout << arr[i] << ", ";
    }
    cout << endl; 
}

int main() {
    
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
    cout << "Const Array\n";
    Print(arr);
    
    for (int i = 0; i < size; ++i) {
        arrCopy[i] = arr[i];
    }

    // Bubble sort
    clock_t start = clock();
    bool swapped = false;
    int temp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    clock_t end = clock();
    double time1 = (double) (end-start) / CLOCKS_PER_SEC;
    Print(arr);

    cout << "\n\n";
    
    // Insert sorting
    start = clock();
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j){
            if (arrCopy[j] < arrCopy[j - 1]) {
                temp = arrCopy[j - 1];
                arrCopy[j - 1] = arrCopy[j];
                arrCopy[j] = temp;
            } else {
                break;
            }
        }
    }
    end = clock();
    double time2 = (double) (end-start) / CLOCKS_PER_SEC;
    Print(arrCopy);

    cout << "Time after bubble sorting = " << time1 << endl;
    cout << "Time after insert sorting = " << time2 << endl;
    return 0;
}