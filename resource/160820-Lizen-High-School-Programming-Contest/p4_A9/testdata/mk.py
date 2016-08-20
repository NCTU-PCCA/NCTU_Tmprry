import random
for i in range(1, 11):
  o = open(str(i).zfill(2) + '.in', 'w')
  o.write(str(i) + ' ')
  o.close()

import random
for i in range(11, 21):
  o = open(str(i).zfill(2) + '.in', 'w')
  o.write(str(random.randint(1, 1000000)) + ' ')
  o.close()


import random
for i in range(21, 31):
  o = open(str(i).zfill(2) + '.in', 'w')
  o.write(str(random.randint(1000000, 100000000000000000)) + ' ')
  o.close()

