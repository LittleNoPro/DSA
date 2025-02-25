from time import *

# Read Input
with open('input.txt', 'r') as file:
    lines = file.readlines()
    arrs = []
    for i in range(0, len(lines), 2):
        n = int(lines[i].strip())
        arrs.append(list(map(int, lines[i + 1].strip().split())))

# Quick Sort
def QuickSort(arr : list, low : int, high : int):
    pivot = arr[(low + high) // 2]
    i, j = low, high

    while i < j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]  # Swap
            i += 1
            j -= 1

    if i < high:
        QuickSort(arr, i, high)
    if j > low:
        QuickSort(arr, low, j)

# Sort and Check time
for arr in arrs:
    start_time = time()
    QuickSort(arr, 0, len(arr) - 1)
    finish_time = time()

    print(f"Array (Sorted in {finish_time - start_time:.6f} seconds)")
