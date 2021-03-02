import sys
import time

import facto


# calculate 20!
FIND_FACTORIAL = 20

print('---- C ----')

start = time.time()
c_result = facto.facto(FIND_FACTORIAL)
print(c_result)
dur_c = time.time() - start
print(f'calculated {FIND_FACTORIAL}! in {dur_c * 1000}ns')

print('---- Python ----')

start = time.time()
result = 1
for i in range(1, FIND_FACTORIAL):
    result *= i
print(result)
dur_py = time.time() - start
print(f'calculated {FIND_FACTORIAL}! in {dur_py * 1000}ns')


# Announce the winner

if dur_c > dur_py:
    print(f'C lost by {(dur_c - dur_py) * 1000}ns')
else:
    print(f'C won by {(dur_py - dur_c) * 1000}ns')

values = (dur_c, dur_py)
difference = (max(values) - min(values)) / max(values)
print('That is a difference of {:.1%}%!'.format(difference))
