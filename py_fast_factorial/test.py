import sys
import time

import facto

FIND_FACTORIAL = 20

start = time.time()
c_result = facto.facto(FIND_FACTORIAL)
dur = time.time() - start
print(f'C: calculated {c_result} in\t\t{dur}s')

start = time.time()
result = 1
for i in range(1, FIND_FACTORIAL):
    result *= i
dur = time.time() - start
print(f'Python: calculated {result} in\t{dur}s')

if c_result != result:
    raise Exception('C got incorrect answer due to no integer overflow handling')
