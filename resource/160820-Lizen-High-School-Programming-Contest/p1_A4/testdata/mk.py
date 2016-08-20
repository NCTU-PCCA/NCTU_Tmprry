import random
for i in range(60,61):
  o = open(str(i).zfill(2) + '.in', 'w')
  a = 100000000000000000
  b = 100000000000000000
  o.write(str(a) + ' ' + str(b))
  o.close()
