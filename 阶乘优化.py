import math
import time
import timeit

# 朴素方法
def f1():
    y = 1
    for i in range(1, 100001):
        y *= i
    return y

# 一点小优化
def f2(s, t):
    if s==t:
        return s
    mid = (s+t)//2
    return f2(s, mid) * f2(mid+1, t)

# 小范围优化
def f3(s, t):
    if t - s < 50:
        r = 1
        for i in range(s, t+1):
            r *= i
        return r
    mid = (s+t)//2
    return f3(s, mid) * f3(mid+1, t)

print(timeit.timeit("f1()", "from __main__ import f1", number = 1))
print(timeit.timeit("f2(1, 100000)", "from __main__ import f2", number = 1))
print(timeit.timeit("f3(1, 100000)", "from __main__ import f3", number = 1))
print(timeit.timeit("math.factorial(100000)", "import math", number=1))