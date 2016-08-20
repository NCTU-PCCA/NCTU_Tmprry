import random
for i in range(21,31):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = 1000
  lst = []
  sm = 0
  for i in range(0, 1000):
    tmp = random.randint(500, 1000)
    lst.append(tmp)
    sm = sm + tmp - 1
  o.write(str(n) + ' ' + str(random.randint(1, min(n*2, sm))) + '\n')
  for i in range(0, 1000):
    o.write(str(lst[i]) + ' ')
  o.close()

import random
for i in range(31,41):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = 1000
  lst = []
  sm = 0
  for i in range(0, 1000):
    tmp = random.randint(200, 300)
    lst.append(tmp)
    sm = sm + tmp - 1
  o.write(str(n) + ' ' + str(random.randint(0.5*n, min(n*2.5, sm))) + '\n')
  for i in range(0, 1000):
    o.write(str(lst[i]) + ' ')
  o.close()

import random
for i in range(41,61):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = 100000
  lst = []
  sm = 0
  for i in range(0, n):
    tmp = random.randint(50000, 1000000000)
    lst.append(tmp)
    sm = sm + tmp - 1
  o.write(str(n) + ' ' + str(random.randint(0.5*n, min(n*2.5, sm))) + '\n')
  for i in range(0, n):
    o.write(str(lst[i]) + ' ')
  o.close()
