#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import tagui as t

t.init()
t.url('https://www.baidu.com')
t.type('q', 'decentralization[enter]')
t.snap('page', 'results.png')
t.close()

