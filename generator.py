#!/usr/bin/env python
import random
import math

n = 10**6
print n

lunused = 0

def rndxy():
    global lunused
    lunused += 1
    x = lunused
    y = random.randint(1,5) + int(math.sqrt(6000.0 * abs(math.cos(math.pi*2.0*x/float(10**6)))))
    return [x,y]

res = map(lambda x: rndxy(), range(n))
res = sorted(res, key=lambda x:x[0])
cx = -1
for i in res:
    cx = max(cx+1, i[0])
    print cx,i[1]
