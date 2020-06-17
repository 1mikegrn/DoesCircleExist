import DoesCircleExist
from os import path
import numpy as np

here = path.abspath(path.dirname(__file__))

with open(path.join(here, 'tests', 'test_cmd.txt'), 'r') as f:
    test_lists = f.read()
    
test_lists = test_lists.split('\n')

res = DoesCircleExist.listCheck(test_lists)

print(res)