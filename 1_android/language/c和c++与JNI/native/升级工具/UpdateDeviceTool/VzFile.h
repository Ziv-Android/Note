#pragma once

#include <ShlObj.h>
#include "Commdlg.h"

#include <vector>
#include <string>
using namespace std;

class CVzFile
{
public:
	CVzFile(void);
	~CVzFile(void);

	static string trim(string s);		 // 去掉string前后的空格
	static bool WriteFile(const char *filepath, unsigned char *pData, unsigned int len); // 二进制写文件
	static bool WriteTxtFile(const char *filepath, LPCSTR strText);
	static bool WriteTxtFileAppend(const char *filepath, LPCSTR strText);
	static string GetAppPath( );
	static int IsPathExist(const char *filename);
	static bool ReplaceStrAll( string &sFile, string sOld, string sNew );
	static wchar_t* c2w(const char *str);
	static bool w2c(const wchar_t* wc, char* dst, int max_len);
	static bool ReadTextFile( const char *filepath, char *buffer, int max_len );
	static string BrowsDir(char *pInitDir, HWND hwnd);
	static string BrowsPath(char *pInitPath, LPCTSTR lpstrFilter, HWND hwnd);
	static int GetLineCount(const char *filepath);
	static void split(std::string& s, std::string& delim, std::vector< std::string >* ret);
};
