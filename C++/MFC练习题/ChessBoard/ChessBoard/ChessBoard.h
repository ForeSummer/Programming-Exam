
// ChessBoard.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CChessBoardApp:
// �йش����ʵ�֣������ ChessBoard.cpp
//

class CChessBoardApp : public CWinApp
{
public:
	CChessBoardApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CChessBoardApp theApp;