import pycees
from os import path
import numpy as np
import time

# test DoesCircleExist
# here = path.abspath(path.dirname(__file__))

# with open(path.join(here, 'tests', 'test_cmd.txt'), 'r') as f:
#     test_lists = f.read()
    
# test_lists = test_lists.split('\n')


# for i in range(1000):

#     test_lists = [
#     ''.join([('R', 'G', 'L')[np.random.randint(0, 3)] for _ in range(1000)])
#     for _ in range(10)]

#     print(pycees.listCheck(test_lists))

# test quickSort
l = [x.item() for x in np.random.random_sample(100000000)]
t1 = time.time()
res = pycees.quickSort(l)
t2 = time.time()
print(t2-t1)
