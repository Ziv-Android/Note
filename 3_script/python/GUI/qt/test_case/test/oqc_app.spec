# -*- mode: python ; coding: utf-8 -*-


block_cipher = None


a = Analysis(['..\\oqc_app.py'],
             pathex=[],
             binaries=[],
             datas=[("..\\lib3rd", "lib3rd"), ("..\\libutils", "libutils"), ("..\\product", "product"), ("..\\docxcompose", "docxcompose")],
             hiddenimports=["lxml._elementpath"],
             hookspath=[],
             hooksconfig={},
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)

exe = EXE(pyz,
          a.scripts,
          [('Aes.js', '..\\libutils\\Aes.js', 'DATA'), ('default.docx', '..\\libutils\\default.docx', 'DATA')],
          [('avcodec-57.dll', '..\\lib3rd\\vzsdk\\avcodec-57.dll', 'BINARY'),('avformat-57.dll', '..\\lib3rd\\vzsdk\\avformat-57.dll', 'BINARY'),
          ('avutil-54.dll', '..\\lib3rd\\vzsdk\\avutil-54.dll', 'BINARY'), ('avutil-55.dll', '..\\lib3rd\\vzsdk\\avutil-55.dll', 'BINARY'),
          ('libwinpthread-1.dll', '..\\lib3rd\\vzsdk\\libwinpthread-1.dll', 'BINARY'), ('swscale-3.dll', '..\\lib3rd\\vzsdk\\swscale-3.dll', 'BINARY'),
          ('VzAudioDataPlayer.dll', '..\\lib3rd\\vzsdk\\VzAudioDataPlayer.dll', 'BINARY'), ('VzDrawsLib.dll', '..\\lib3rd\\vzsdk\\VzDrawsLib.dll', 'BINARY'),
          ('VzLPRSDK.dll', '..\\lib3rd\\vzsdk\\VzLPRSDK.dll', 'BINARY'), ('VzPlayer2.dll', '..\\lib3rd\\vzsdk\\VzPlayer2.dll', 'BINARY'),
          ('VzStreamClient.dll', '..\\lib3rd\\vzsdk\\VzStreamClient.dll', 'BINARY'), ],
          exclude_binaries=True,
          name='oqc_app',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          console=True,
          disable_windowed_traceback=False,
          target_arch=None,
          codesign_identity=None,
          entitlements_file=None )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas,
               strip=False,
               upx=True,
               upx_exclude=[],
               name='oqc_app')
