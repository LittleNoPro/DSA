#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;  // Thư viện đo thời gian

void Heapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

// Heap Sort
void HeapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
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
    for (size_t i = 0; i < arrs.size(); i++) {
        auto start = high_resolution_clock::now();
        HeapSort(arrs[i]);
        auto end = high_resolution_clock::now();

        duration<double> exec_time = end - start;

        cout << "Array " << i + 1 << " (Sorted in " << exec_time.count() << " seconds)" << endl;
    }

    return 0;
}
