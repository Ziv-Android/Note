import xlwings as xw
import os

# path = '.\\a.xlsx'
#
# app = xw.App(visible=True, add_book=False)
# if not os.path.exists(path):
#     file_new = app.books.add()
#     file_new.save(path)
#
# app.quit()

path = '.\\HV08P.xls'

app = xw.App(visible=True, add_book=False)
wb = app.books.open(path)

print(app.books)
print(app.books.active)

print(wb.sheets[0].name)

# app.quit()
