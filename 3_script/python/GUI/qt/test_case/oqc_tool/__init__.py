import ctypes
import os

path = os.path.realpath(os.path.join(os.getcwd(), "lib3rd/vzsdk"))
print(path)
os.environ['path'] += f';{path}'

# 调用VZSDK
objdll = ctypes.cdll.LoadLibrary('./lib3rd/vzsdk/VzLPRSDK.dll')
