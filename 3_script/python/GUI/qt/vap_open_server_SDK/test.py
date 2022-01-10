# coding: utf-8

import requests


class Ocs(object):

    def __init__(self):
        self.base_url = 'http://admin.vzpdns.com'
        self.ocs = requests.session()
        self.header = {'Content-Type': 'application/json', 'Authorization': self.login()}

    def login(self):
        request_url = self.base_url + '/adminapi/v1/pms/admins/login_password'
        body = {"username": "admin", "password": "e10adc3949ba59abbe56e057f20f883e"}
        result = self.ocs.post(request_url, headers={'Content-Type': 'application/json'}, json=body)
        return result.json()['token']['access']

    def deposit(self, company_id, order):
        request_url = self.base_url + '/adminapi/v1/ocs/companies/%d/recharge' % company_id
        body = {"amount_money": order * 100, "reason": ""}
        result = self.ocs.post(request_url, headers=self.header, json=body)
        print(result.json())

    def change_package(self, company_id, package_id):
        request_url = self.base_url + '/adminapi/v1/ocs/companies/%d/packages/%d' % (company_id, package_id)
        result = self.ocs.post(request_url, headers=self.header)
        print(result.json())


if __name__ == '__main__':
    ocs = Ocs()
    ocs.deposit(2, 10000)
    # for i in range(1, 362):
    #     if i != 52:
    #         ocs.deposit(i, 73120)
            # ocs.change_package(i, 4)
