
// �˻ʺ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�˻ʺ�App:
// �йش����ʵ�֣������ �˻ʺ�.cpp
//

class C�˻ʺ�App : public CWinApp
{
public:
	C�˻ʺ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�˻ʺ�App theApp;