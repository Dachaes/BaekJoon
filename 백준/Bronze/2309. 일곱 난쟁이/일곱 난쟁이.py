# BOJ_2309 : 일곱 난쟁이
import sys
from itertools import combinations

dwarfs = [int(sys.stdin.readline()) for _ in range(9)]
dwarfs_7 = combinations(dwarfs, 7)

results = []
for dwarf_7 in dwarfs_7:
    if sum(dwarf_7) == 100:
        results = sorted(dwarf_7)
        break

for result in results:
    print(result)