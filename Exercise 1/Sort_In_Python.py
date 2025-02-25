from time import *
from numpy import *

# Read Input
with open('input.txt', 'r') as file:
    lines = file.readlines()
    arrs = []
    for i in range(0, len(lines), 2):
        n = int(lines[i].strip())
        arrs.append(list(map(int, lines[i + 1].strip().split())))

# Sort and Check time
for arr in arrs:
    start_time = time()
    sorted_arr = sort(array(arr))
    finish_time = time()

    print(f"Array (Sorted in {finish_time - start_time:.6f} seconds)")
