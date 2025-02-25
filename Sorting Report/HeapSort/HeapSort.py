from time import *

# Read Input
with open('input.txt', 'r') as file:
    lines = file.readlines()
    arrs = []
    for i in range(0, len(lines), 2):
        n = int(lines[i].strip())
        arrs.append(list(map(int, lines[i + 1].strip().split())))

# Heap Sort
def Heapify(arr : list, n : int, i : int):
    largest = i
    low = 2 * i + 1
    high = 2 * i + 2

    if low < n and arr[i] < arr[low]:
        largest = low
    if high < n and arr[largest] < arr[high]:
        largest = high

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap

        Heapify(arr, n, largest)

def HeapSort(arr : list):
    n = len(arr)

    for i in range(n // 2, -1, -1):
        Heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # Swap

        Heapify(arr, i, 0)

# Sort and Check time
for arr in arrs:
    start_time = time()
    HeapSort(arr)
    finish_time = time()

    print(f"Array (Sorted in {finish_time - start_time:.6f} seconds)")
