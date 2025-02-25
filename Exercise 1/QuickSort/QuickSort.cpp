#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

// Quick Sort
void QuickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[(low + high) / 2];
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
            swap(arr[i++], arr[j--]);
    }

    if (low < j) QuickSort(arr, low, j);
    if (i < high) QuickSort(arr, i, high);
}

int main() {
    ifstream inputFile("input.txt");
    vector<vector<int>> arrs;
    string line;

    // Read Input
    while (getline(inputFile, line)) {
        int n = stoi(line), num;
        vector<int> arr;

        if (getline(inputFile, line)) {
            stringstream ss(line);
            while (ss >> num)
                arr.push_back(num);
        }

        arrs.push_back(arr);
    }

    inputFile.close();

    // Sort and Check Time
    for (int i = 0; i < arrs.size(); i++) {
        auto start = high_resolution_clock::now();
        QuickSort(arrs[i], 0, arrs[i].size() - 1);
        auto end = high_resolution_clock::now();

        duration<double> exec_time = end - start;

        cout << "Array " << i + 1 << " (Sorted in " << exec_time.count() << " seconds)" << endl;
    }

    return 0;
}
