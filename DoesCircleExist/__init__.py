from DoesCircleExist import tools

def listCheck(input_list):
    res = tools.cExt.listCheck(input_list)
    return ['YES' if x == 1 else 'NO' for x in res]