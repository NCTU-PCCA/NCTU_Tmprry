import random
for i in range(1, 21):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(1, 6)
  m = random.randint(1, 6)
  lst = []
  sm = 0
  o.write(str(n) + ' ' + str(m) + '\n')
  for i in range(0, 6):
    lst.append(random.randint(0, 1000000))
  o.write(str(lst[0]) + ' ' + str(lst[1]) + ' ' + str(lst[2]) + '\n')
  o.write(str(lst[1]) + ' ' + str(lst[3]) + ' ' + str(lst[4]) + '\n')
  o.write(str(lst[2]) + ' ' + str(lst[4]) + ' ' + str(lst[5]) + '\n')
  for j in range(0, n):
    for i in range(0, m):
      o.write(str(random.randint(0, 2)) + ' ')
    o.write('\n')
  o.close()


import random
for i in range(21, 31):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(1, 100)
  m = random.randint(1, 100)
  lst = []
  sm = 0
  o.write(str(n) + ' ' + str(m) + '\n')
  for i in range(0, 6):
    lst.append(random.randint(0, 1000000))
  o.write(str(lst[0]) + ' ' + str(lst[1]) + ' ' + str(lst[2]) + '\n')
  o.write(str(lst[1]) + ' ' + str(lst[3]) + ' ' + str(lst[4]) + '\n')
  o.write(str(lst[2]) + ' ' + str(lst[4]) + ' ' + str(lst[5]) + '\n')
  for j in range(0, n):
    for i in range(0, m):
      o.write(str(random.randint(0, 2)) + ' ')
    o.write('\n')
  o.close()


import random
for i in range(31, 45):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(1, 1000)
  m = random.randint(1, 1000)
  lst = []
  sm = 0
  o.write(str(n) + ' ' + str(m) + '\n')
  for i in range(0, 6):
    lst.append(random.randint(0, 1000000))
  o.write(str(lst[0]) + ' ' + str(lst[1]) + ' ' + str(lst[2]) + '\n')
  o.write(str(lst[1]) + ' ' + str(lst[3]) + ' ' + str(lst[4]) + '\n')
  o.write(str(lst[2]) + ' ' + str(lst[4]) + ' ' + str(lst[5]) + '\n')
  for j in range(0, n):
    for i in range(0, m):
      o.write(str(random.randint(0, 2)) + ' ')
    o.write('\n')
  o.close()

import random
for i in range(45, 46):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = 1000
  m = 1000
  lst = []
  sm = 0
  o.write(str(n) + ' ' + str(m) + '\n')
  for i in range(0, 6):
    lst.append(random.randint(0, 1000000))
  o.write(str(lst[0]) + ' ' + str(lst[1]) + ' ' + str(lst[2]) + '\n')
  o.write(str(lst[1]) + ' ' + str(lst[3]) + ' ' + str(lst[4]) + '\n')
  o.write(str(lst[2]) + ' ' + str(lst[4]) + ' ' + str(lst[5]) + '\n')
  for j in range(0, n):
    for i in range(0, m):
      o.write(str(random.randint(0, 2)) + ' ')
    o.write('\n')
  o.close()
