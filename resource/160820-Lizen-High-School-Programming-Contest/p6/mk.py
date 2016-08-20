import random
for i in range(1, 21):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(3, 5)
  o.write(str(n) + '\n')
  for j in range(0, n):
    w = random.randint(0, 1)
    if w == 0:
      c = 'L'
    else:
      c = 'R'
    o.write(c)
  o.close()


import random
for i in range(21, 41):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(5, 12)
  o.write(str(n) + '\n')
  for j in range(0, n):
    w = random.randint(0, 1)
    if w == 0:
      c = 'L'
    else:
      c = 'R'
    o.write(c)
  o.close()



import random
for i in range(41, 51):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(1, 1000)
  o.write(str(n) + '\n')
  for j in range(0, n):
    w = random.randint(0, 1)
    if w == 0:
      c = 'L'
    else:
      c = 'R'
    o.write(c)
  o.close()

import random
for i in range(51, 60):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = random.randint(1, 1000000)
  o.write(str(n) + '\n')
  for j in range(0, n):
    w = random.randint(0, 1)
    if w == 0:
      c = 'L'
    else:
      c = 'R'
    o.write(c)
  o.close()

import random
for i in range(60, 61):
  o = open(str(i).zfill(2) + '.in', 'w')
  n = 1000000
  o.write(str(n) + '\n')
  w = 0
  for j in range(0, n):
    w = 1-w
    if w == 0:
      c = 'L'
    else:
      c = 'R'
    o.write(c)
  o.close()
