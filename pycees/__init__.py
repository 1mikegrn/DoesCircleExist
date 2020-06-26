from pycees import tools

def listCheck(input_list):
    res = tools.DoesCircleExist.listCheck(input_list)
    return ['YES' if x == 1 else 'NO' for x in res]

# def quickSort(input_list):
#     return tools.cExt.quickSort(input_list)