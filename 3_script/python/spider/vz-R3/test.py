#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from libutils.SessionClient import *


client = SessionClient("http://192.168.13.202", "admin", "admin")
client.login()
