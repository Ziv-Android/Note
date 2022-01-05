import glob
import os.path
import subprocess


def ex(cmd):
    print("ex", cmd)
    subprocess.call(cmd, shell=True)


def ui_to_py():
    ui_files = glob.glob(os.path.join("./", "*.ui"))
    print(ui_files)
    for ui_file in ui_files:
        file_name = ui_file[2:-2] + "py"
        ex(f"python -m PyQt5.uic.pyuic {ui_file} -o ui_{file_name}")


if __name__ == '__main__':
    ui_to_py()
