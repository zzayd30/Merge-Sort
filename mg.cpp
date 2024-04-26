#include <iostream>
using namespace std;
void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[10] = {}, R[10] = {};
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}
int main() {
    int arr[10] = { 4, 23, 70, 2, 8, 39, 40, 3, 56, 0 };
    MergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
