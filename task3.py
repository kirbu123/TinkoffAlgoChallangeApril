n = int(input())

data = dict()

root = str()

for i in range(n):
  inp = str(input())
  mas = inp.split(sep='/')
  for i in range(len(mas)):
    if (mas[i], i) not in data.keys():
      data[(mas[i], i)] = []
    if (i > 0):
      if (mas[i] not in data[(mas[i - 1], i - 1)]):
        data[(mas[i - 1], i - 1)].append(mas[i])
    else:
      root = mas[i]
for i in data.keys():
  data[i].sort()

def rec(elem, level):
  global data
  print('  ' * level, end='')
  print(elem)
  for i in data[(elem, level)]:
    rec(i, level + 1)

rec(root, 0) 

