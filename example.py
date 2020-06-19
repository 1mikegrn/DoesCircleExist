import DoesCircleExist
from os import path
import numpy as np

here = path.abspath(path.dirname(__file__))

with open(path.join(here, 'tests', 'test_cmd.txt'), 'r') as f:
    test_lists = f.read()
    
test_lists = test_lists.split('\n')


for i in range(1000):

    test_lists = [
    ''.join([('R', 'G', 'L')[np.random.randint(0, 3)] for _ in range(1000)])
    for _ in range(10)]

    print(DoesCircleExist.listCheck(test_lists))


   