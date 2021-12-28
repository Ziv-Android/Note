#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time
import os

from docx import Document
from docx.shared import Pt
from docx.shared import Inches
from docx.shared import Cm
from docx.oxml.ns import qn

from PIL import Image
from pydocx import PyDocX
import collections


class WordReport:
    def __init__(self):
        self.sn = ""
        self.base_info = None
        self.start_time = 0
        self.filename = None
        self.document = None

    def reset_flag(self):
        self.sn = ""
        self.start_time = 0
        self.filename = None
        self.document = None

    def save_doc(self, filename=None):
        self.filename = filename
        _doc_path = os.path.join(os.getcwd(), "doc")
        if not os.path.exists(_doc_path):
            os.makedirs(_doc_path)
        if self.filename is None:
            self.filename = time.strftime('%Y-%m-%d-%H-%M-%S', time.localtime((time.time()))) + '.docx'
        _report_filename = os.path.join(_doc_path, f"测试报告-{self.filename}")
        self.document.save(_report_filename)

    def doc2html(self, filename=None):
        if self.filename is None:
            self.filename = filename
        if self.filename is None:
            return ""
        _doc_path = os.path.join(os.getcwd(), "doc")
        _report_doc_path = os.path.join(_doc_path, f"测试报告-{self.filename}")
        _report_html_path = os.path.join(_doc_path, "index.html")
        with open(_report_html_path, "w", encoding="utf-8") as wf:
            html_content = PyDocX.to_html(_report_doc_path)
            wf.write(html_content)
        self.reset_flag()
        return _report_html_path, html_content

    def delete_pic(self):
        try:
            _pic_path = os.path.join(os.getcwd(), "doc", "pic")
            if not os.path.exists(_pic_path):
                os.makedirs(_pic_path)
            for item in os.listdir(_pic_path):
                os.remove(os.path.join(_pic_path, item))
        except Exception as e:
            print("delete_pic", e)

    def get_empty_params(self):
        return collections.OrderedDict()

    def report_basic(self, results):
        self.base_info = results

    def report_sn(self, sn):
        if self.sn == "":
            self.sn = sn
            self.write_content(f"设备序号：{self.sn}")

    def report_start(self, start_time):
        if self.start_time == 0:
            path = os.path.join(os.getcwd()) + "\\libutils\\default.docx"
            print(path)
            self.document = Document(path)
            self.write_title("基本信息", 1)
            if self.base_info is not None:
                self.write_report_map(self.base_info)
            self.start_time = start_time
            time_format = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time))
            self.write_content(f"测试时间：{time_format}")

    def report_video(self, results):
        self.write_title("图像云台测试", 1)
        self.write_report_map(results)

    def report_extern(self, results):
        self.write_title("外部接口测试", 1)
        self.write_report_map(results)

    def report_end(self, result, end):
        self.write_title("测试结果", 1)
        self.write_content(f"测试结果：{result}, 测试耗时：{int(end - self.start_time)}s")

    def write_report_map(self, results):
        for item_key in results.keys():
            item_value = results.get(item_key, "").strip()
            if item_value.endswith((".jpg", ".png")):
                self.write_content(f"{item_key}：")
                self.write_pic(item_value)
            else:
                self.write_content(f"{item_key}：{item_value}")
            print("report:", item_key, results.get(item_key))

    def write_title(self, title, level):
        self.document.add_heading(title, level)

    def write_content(self, content):
        self.document.add_paragraph(content)

    def write_pic(self, pic_path):
        pic = Image.open(pic_path)
        if pic.mode == "P":
            pic = pic.convert("RGB")
        pic.save(pic_path, quality=100)
        self.document.add_picture(pic_path, width=Cm(15.2))

    def write_list(self, header_list, data, style="Table Grid"):
        # row行, col列
        table_col = len(header_list)
        # 新建一个1行n列的表头
        table = self.document.add_table(1, table_col)
        header_cells = table.rows[0].cells
        for i in range(len(header_cells)):
            header_cells[i].text = header_list[i]

        for item in data:
            row_cells = table.add_row().cells
            for i in range(len(row_cells)):
                row_cells[i].text = str(item[i])

        table.style = style

    def write_page_break(self):
        self.document.add_page_break()


report_doc = WordReport()

# [Python-docx使用](https://zhuanlan.zhihu.com/p/82880510)
# [python-docx官方文档](https://python-docx.readthedocs.io/en/latest/)
