ERROR_MSG = 'ERROR'  # 遇到除数是 0 的时候的报错


def evaluateExpression(expression):
    """将 str 类型的表达式使用 eval 来计算得到结果, 例如 eval('1+1')=2
    Args:
        expression (str): 计算表达式, 例如 '1+2'
    """
    try:
        result = str(eval(expression))
    except Exception:
        result = ERROR_MSG
    return result
