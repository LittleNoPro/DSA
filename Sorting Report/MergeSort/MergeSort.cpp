#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

void MergePart(vector<int>& arr, int low, int mid, int high) {
    int i = low, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= high)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[low + k] = temp[k];
}

void MergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    MergePart(arr, low, mid, high);
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
        MergeSort(arrs[i], 0, arrs[i].size() - 1);
        auto end = high_resolution_clock::now();

        duration<double> exec_time = end - start;

        cout << "Array " << i + 1 << " (Sorted in " << exec_time.count() << " seconds)" << endl;
    }

    return 0;
}
