
// PingTu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPingTuApp:
// �йش����ʵ�֣������ PingTu.cpp
//

class CPingTuApp : public CWinApp
{
public:
	CPingTuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPingTuApp theApp;