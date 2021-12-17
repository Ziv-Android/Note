import os
import os.path

# UI文件所在路径
ui_dir = './'


# 列出目录下的所有UI文件
def listUiFile():
    lists = []
    files = os.listdir(ui_dir)
    for filename in files:
        # print(ui_dir + os.sep + filename)
        if os.path.splitext(filename)[1] == '.ui':
            lists.append(filename)

    return lists


def transPyFile(filename):
    return os.path.splitext(filename)[0] + '.py'

def runMain():
    lists = listUiFile()
    for uifile in lists:
        pyfile = transPyFile(uifile)
        cmd = 'pyuic5 -o ui_{pyfile} {uifile}'.format(pyfile=pyfile, uifile=uifile)
        print(cmd)
        os.system(cmd)


if __name__ == '__main__':
    runMain()
