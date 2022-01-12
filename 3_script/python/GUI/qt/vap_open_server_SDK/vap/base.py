# coding: utf-8
import requests


def return_data(response):
    if 'text/plain' in response.headers['Content-Type']:
        return response.text
    else:
        return response.json()


def get(url, **kwargs):
    """封装get方法"""
    try:
        result = requests.get(url, **kwargs)
        print(kwargs)
        print(result.status_code)
        return {'code': 0, 'message': 'success', 'data': return_data(result)}
    except Exception as e:
        return {'code': 1006, 'message': "get请求错误: %s" % e}


def post(url, **kwargs):
    """封装post方法"""
    try:
        result = requests.post(url, **kwargs)
        return {'code': 0, 'message': 'success', 'data': return_data(result)}
    except Exception as e:
        return {'error': 1006, 'message': "post请求错误: %s" % e}


def put(url, **kwargs):
    """封装put方法"""
    try:
        result = requests.put(url, **kwargs)
        return {'code': 0, 'message': 'success', 'data': return_data(result)}
    except Exception as e:
        return {'error': 1006, 'message': "put请求错误: %s" % e}


def delete(url, **kwargs):
    """封装delete方法"""
    try:
        result = requests.delete(url, **kwargs)
        return {'code': 0, 'message': 'success', 'data': return_data(result)}
    except Exception as e:
        return {'error': 1006, 'message': "delete请求错误: %s" % e}


def request(timeout=60, **kwargs):
    kwargs['timeout'] = timeout
    url = kwargs.get('url')
    method = kwargs.get('method')
    del kwargs['method']
    del kwargs['url']

    if method.upper() == 'GET':
        return get(url, **kwargs)
    elif method.upper() == 'POST':
        return post(url, **kwargs)
    elif method.upper() == 'PUT':
        return put(url, **kwargs)
    elif method.upper() == 'DELETE':
        return delete(url, **kwargs)
    else:
        return {'error': 1007, 'message': '暂不支持该请求方法或请求方式错误'}

