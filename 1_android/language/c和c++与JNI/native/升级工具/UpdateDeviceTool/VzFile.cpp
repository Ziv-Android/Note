//#include "StdAfx.h"
#include "VzFile.h"

#include <io.h>
#include <ShlObj.h>
#include <fstream>

CVzFile::CVzFile(void)
{
}

CVzFile::~CVzFile(void)
{
}

string CVzFile::trim(string s)
{
	string sResult = s;

    if (sResult.empty()) 
    {
        return sResult;
    }
	
    sResult.erase(0,sResult.find_first_not_of(" "));
    sResult.erase(sResult.find_last_not_of(" ") + 1);
    return sResult;
}


bool CVzFile::WriteFile(const char *filepath, unsigned char *pData, unsigned int len)
{
	int num = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "wb+");

	if( fp == NULL )
	{
		return false;
	}

	num = fwrite( pData, sizeof(char), len, fp );
	fclose( fp );

	return num > 0;
}

int CVzFile::GetLineCount(const char *filepath)
{
	int count = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "r");

	if (fp == NULL) {
		return 0;
	}

	const int max_len = 1024;
	char buffer[max_len] = { 0 };

	while (fgets(buffer, max_len, fp) != NULL) {
		count++;
	}

	fclose(fp);
	return count;
}

bool CVzFile::WriteTxtFile(const char *filepath, LPCSTR strText)
{
	int num = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "w+");

	if( fp == NULL )
	{
		return false;
	}

	num = fwrite( strText, sizeof(char), strlen(strText), fp );
	fclose( fp );

	return num > 0;
}

bool CVzFile::WriteTxtFileAppend(const char *filepath, LPCSTR strText)
{
	int num = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "a+");

	if (fp == NULL)
	{
		return false;
	}

	num = fwrite(strText, sizeof(char), strlen(strText), fp);
	fclose(fp);

	return num > 0;
}

// 获取当前程序路径
string CVzFile::GetAppPath()
{
	string sAppPath;
    
    TCHAR tszModule[MAX_PATH + 1] = { 0 };
    ::GetModuleFileName(NULL, tszModule, MAX_PATH);
    
	sAppPath.assign((char*)tszModule);
	int pos = sAppPath.find_last_of('\\');
	sAppPath = sAppPath.substr(0, pos);
	
	return sAppPath;
}

int CVzFile::IsPathExist(const char *filename)   
{   
	return (_access(filename, NULL) == 0);
}

// 替换所有字符串
bool CVzFile::ReplaceStrAll( string &sFile, string sOld, string sNew )
{
	bool ret = false;
	int nLength = sOld.length();

	int nPos = -1;
	do
	{
		nPos = sFile.find( sOld );
		if( nPos < 0 )
		{
			break;
		}

		sFile.replace(nPos, nLength, sNew);
		ret = true;
	}
	while( nPos >= 0 );

	return ret;
}

wchar_t* CVzFile::c2w(const char *str)
{
	int length = strlen(str)+1;
	wchar_t *t = (wchar_t*)malloc(sizeof(wchar_t)*length);
	memset(t,0,length*sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP,0,str,strlen(str),t,length);

	return t;
}

bool CVzFile::ReadTextFile( const char *filepath, char *buffer, int max_len )
{
	int num = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "r");

	if( fp == NULL )
	{
		return false;
	}

	num = fread( buffer, sizeof(char), max_len, fp );
	fclose( fp );

	return num > 0;
}

int CALLBACK _SHBrowseForFolderCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	if(uMsg == BFFM_INITIALIZED)
	{
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
	}

	return 0;
}

void CVzFile::split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);

	while (index != std::string::npos)
	{
		ret->push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}

	if (index - last>0)
	{
		ret->push_back(s.substr(last, index - last));
	}
}

string CVzFile::BrowsDir(char *pInitDir, HWND hwnd)
{
	char szDirPath[MAX_PATH] = {0};
	BROWSEINFO bi; 
	ITEMIDLIST * pidl;

	bi.hwndOwner = hwnd; 
	bi.pidlRoot = NULL; 
	bi.pszDisplayName = szDirPath; 
	bi.lpszTitle = "请选择文件夹"; 
	bi.ulFlags = BIF_RETURNONLYFSDIRS; 
	bi.lpfn = _SHBrowseForFolderCallbackProc; 
	bi.lParam = (LPARAM)pInitDir; 
	bi.iImage = 0; 

	pidl = SHBrowseForFolder(&bi);
	if(pidl == NULL)
	{
		return "";
	}

	if(!SHGetPathFromIDList(pidl,szDirPath))
	{
		szDirPath[0] = '\0';
	}

	int nPathLen = strlen(szDirPath);
	if(nPathLen > 0 && szDirPath[nPathLen-1] == '\\')
	{
		szDirPath[nPathLen-1] = '\0';
	}

	//释放内存
	LPMALLOC pMalloc;
	if (SUCCEEDED(SHGetMalloc(&pMalloc)))
	{
		pMalloc->Free(pidl);
		(void)pMalloc->Release();
	}

	string sDir(szDirPath);
	return sDir;
}

string CVzFile::BrowsPath(char *pInitPath, LPCTSTR lpstrFilter, HWND hwnd)
{
	string sPath;

	// 获取开始当前文件所在的目录
	string sInitDir;
	string sInitPath(pInitPath);

	int nPos = sInitPath.find_last_of("\\");
	if ( nPos > 0 )
	{
		sInitDir = sInitPath.substr(0, nPos+1);
	}


	// 打开文件打开对话框，如果选中文件，则
	OPENFILENAME ofn;      // 公共对话框结构。
	char szFile[MAX_PATH] = {0}; // 保存获取文件名称的缓冲区。			

	// 初始化选择文件对话框。
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = lpstrFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = sInitDir.c_str();
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// 显示打开选择文件对话框。
	if ( GetOpenFileName(&ofn) )
	{
		sPath.assign(szFile);
	}

	return sPath;
}

bool CVzFile::w2c(const wchar_t* wc, char* dst, int max_len)
{
	int len = WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), NULL, 0, NULL, NULL);
	if (len >= max_len)
	{
		return false;
	}

	WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), dst, len, NULL, NULL);
	dst[len] = '\0';

	return true;
}