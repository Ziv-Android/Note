// MaintenTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMaintenToolApp:
// �йش����ʵ�֣������ MaintenTool.cpp
//

class CMaintenToolApp : public CWinApp
{
public:
	CMaintenToolApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMaintenToolApp theApp;