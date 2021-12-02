#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# import tagui as t
#
# t.init()
# t.url('https://www.baidu.com')
# t.type('q', 'decentralization[enter]')
# t.snap('page', 'results.png')
# t.close()

import rpa as r

r.init()
r.url('https://www.baidu.com')
r.type('//*[@name="q"]', 'decentralization[enter]')
r.snap('page', 'results.png')
r.close()


