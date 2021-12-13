import json
import requests


class NormalClient:
    def get(self, url, params):
        print("NormalClient", "get", url, params)
        return requests.get(url, params)
        
    def post(self, url, params):
        return requests.post(url, params)
