#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from functools import wraps
import time


def cost_time(func):
    @wraps(func)
    def func_cost_time(*args, **kwargs):
        print("%s start." % func.__name__)
        start_time = time.time()
        result = func(*args, **kwargs)
        print("%s finish, cost %s ms." % (func.__name__, int(time.time() - start_time)))
        return result
    return func_cost_time


@cost_time
def func_long():
    time.sleep(1.0)
    return 111


if __name__ == "__main__":
    f = func_long()
    print("f is", f)
