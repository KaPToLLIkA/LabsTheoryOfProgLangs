from bisect import bisect_left
from heapq import merge

class Pile(list):
    def __lt__(self, other): return self[-1] < other[-1]
    def __eq__(self, other): return self[-1] == other[-1]

def patience_sort(n):
    piles = []
    for x in n:
        new_pile = Pile([x])
        i = bisect_left(piles, new_pile)
        if i != len(piles):
            piles[i].append(x)
        else:
            piles.append(new_pile)

    n[:] = merge(*[reversed(pile) for pile in piles])


a = [4, 65, 2, -31, 0, 99, 83, 782, 1]
patience_sort(a)
print(a)
