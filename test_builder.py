from os import path
import numpy as np

def build():
    here = path.abspath(path.dirname(__file__))

    sequences = 10
    letters = 100000

    commands = [
        ''.join(
            [('R', 'G', 'L')[np.random.randint(0, 3)] for _ in range(letters)]
        )
        for _ in range(sequences)
    ]

    with open(path.join(here, 'tests', 'test_cmd.txt'), 'w') as w:
        w.writelines(
            [x+'\n' if x != commands[-1] else x
            for x in commands]
        )


if __name__ == "__main__":
    build()

