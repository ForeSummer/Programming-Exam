
// Calculator1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCalculator1App:
// �йش����ʵ�֣������ Calculator1.cpp
//

class CCalculator1App : public CWinApp
{
public:
	CCalculator1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCalculator1App theApp;