from time import *

# Read Input
with open('input.txt', 'r') as file:
    lines = file.readlines()
    arrs = []
    for i in range(0, len(lines), 2):
        n = int(lines[i].strip())
        arrs.append(list(map(int, lines[i + 1].strip().split())))

# Merge Sort
def MergePart(arr : list, low : int, mid : int, high : int):
    i, j = low, mid + 1

    temp = []
    while i <= mid and j <= high:
        if arr[i] < arr[j]:
            nextVal = arr[i]
            i += 1
        else:
            nextVal = arr[j]
            j += 1

        temp.append(nextVal)

    while i <= mid:
        temp.append(arr[i])
        i += 1
    while j <= high:
        temp.append(arr[j])
        j += 1

    for i in range(len(temp)):
        arr[low + i] = temp[i]

def MergeSort(arr : list, low : int, high : int):
    if low >= high:
        return

    mid = (low + high) // 2

    MergeSort(arr, low, mid)
    MergeSort(arr, mid + 1, high)

    MergePart(arr, low, mid, high)


# Sort and Check time
for arr in arrs:
    start_time = time()
    MergeSort(arr, 0, len(arr) - 1)
    finish_time = time()

    print(f"Array (Sorted in {finish_time - start_time:.6f} seconds)")
