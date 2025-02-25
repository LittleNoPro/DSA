#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

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
        sort(arrs[i].begin(), arrs[i].end());
        auto end = high_resolution_clock::now();

        duration<double> exec_time = end - start;

        cout << "Array " << i + 1 << " (Sorted in " << exec_time.count() << " seconds)" << endl;
    }

    return 0;
}