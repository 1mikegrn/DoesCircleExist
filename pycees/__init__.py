from pycees import tools

def listCheck(input_list):
    res = tools.DoesCircleExist.listCheck(input_list)
    return ['YES' if x == 1 else 'NO' for x in res]

def quickSort(input_list):
    assert (
        isinstance(input_list, list) is True 
        & isinstance(input_list[0], float) is True
        ), (
            "passed object should be a Python list of Python floats"
        )

    return tools.quickSort.quickSort(input_list)