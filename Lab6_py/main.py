from bisect import bisect_left
from heapq import merge
from tkinter import *


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

def show_message():
    str = txt.get().replace(' ', '')
    a = str.split(",")
    patience_sort(a)
    lbl['text'] = a


window = Tk()
window.title("Laba6")
window.geometry('400x250')
lbl = Label(window, text="Введите целые числа через запятую")
lbl.grid(column=0, row=0, sticky=W, pady=(10, 0), padx=(2, 0))

txt = Entry(window, width=50)
txt.grid(column=0, row=1, sticky=W, pady=(10, 0), padx=(2, 0))

btn = Button(window, text="Сортировать", command=show_message)
btn.grid(column=0, row=2, sticky=W, pady=(10, 0), padx=(2, 0))

lbl = Label(window, text="")
lbl.grid(column=0, row=3, sticky=W, pady=(10, 0), padx=(2, 0))

window.mainloop()