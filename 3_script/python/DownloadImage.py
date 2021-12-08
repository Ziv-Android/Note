#!/usr/bin/env python
# encoding:UTF-8

import re
import urllib
import threading
import time
import queue

import requests

url_home = "https://image.baidu.com/search/index?tn=baiduimage&word=%E7%BE%8E%E5%A5%B3"
url_test = "https://img0.baidu.com/it/u=3800037915,2368949556&fm=26&fmt=auto"

header = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'
}


def getImageUrls():
    with open("images.txt", "r") as of:
        return of.readlines()


def getImageData(url):
    requests.get(url, )


data_list = getImageUrls()
print(data_list)
# def getImageData(url):
#     r = requests.get(url)
# def getHtml(url):
#     r = requests.get(url, headers=header)
#     return r.content
#     # html_page = urllib.urlopen().read()
#     # return html_page


# html_page = getHtml(url_test)
# print(html_page)

# 提取网页中图片的URL
def getUrl(html):
    pattern = r'http://.*?\.jpg!mid'  # 正则表达式  .*?(匹配http://和\.jpg!mid之间所有字符串)
    imgre = re.compile(pattern)
    imglist = re.findall(imgre, html)  # re.findall(pattern,string)  在string中寻找所有匹配成功的字符串，以列表形式返回值
    return imglist


class getImg(threading.Thread):
    def __init__(self, _queue):  # 进程间通过队列通信，所以每个进程需要用到同一个队列初始化
        threading.Thread.__init__(self)
        self.myQueue = _queue
        # self.setDaemon(True)         #守护线程
        self.start()  # 启动线程

    # 使用队列实现进程间通信
    def run(self):
        global count
        while (True):
            imgurl = self.myQueue.get()
            # print self.getName()

            # urllib.urlretrieve(url,filname) 将url的内容提取出来，并存入filename中
            urllib.urlretrieve(imgurl, '/home/dragonriver/图片/girls/%s.jpg' % count)
            #	print "%s.jpg done"%count
            count += 1
            if self.myQueue.empty():
                break
            self.myQueue.task_done()  # 当使用者线程调用 task_done() 以表示检索了该项目、并完成了所有的工作时，那么未完成的任务的总数就会减少。


def main():
    global count
    url = "http://girl-atlas.com/a/10130205170100000231"  # 要爬的网页地址
    html = getHtml(url)
    print(html)
    # imglist = getUrl(html)
    # threads = []
    # count = 0
    # myQueue = queue.Queue()
    #
    # # 将所有任务加入队列
    # for i in range(len(imglist)):
    #     myQueue.put(imglist[i])
    #
    # # 多线程爬去图片
    # for i in range(4):
    #     thread = getImg(myQueue)
    #     threads.append(thread)


# 合并进程，当子进程结束时，主进程才可以执行
# for thread in threads:
#	thread.join()

# 另一种保持主进程阻塞的方法，次方法和前面的self.queue.task_tone()相照应
# 两个要同时使用
# queue.join()


# if __name__ == '__main__':
#     main()
#     print("Down")
