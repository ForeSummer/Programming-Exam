
// LightView.h : CLightView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include <vector>
using namespace std;

struct Position{
	int x;
	int y;
};

class CLightView : public CFormView
{
protected: // �������л�����
	CLightView();
	DECLARE_DYNCREATE(CLightView)

public:
	enum{ IDD = IDD_LIGHT_FORM };

// ����
public:
	CLightDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CLightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	enum CHESS{MIRROR_0,MIRROR_45,MIRROR_90,MIRROR_145,LIGHT,RED,BLANK};
	CHESS** chesses;
	int m;
	int n;
	int r;
	int align;
	int width;
	vector<Position>red_vector;
	void drawChessBoard();
	void drawChess();
	bool canPlace(int x,int y);
	void initChessBoard(int m,int n);
	afx_msg void OnBnClickedGenerateChess();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedOpen();
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedClear();
};

#ifndef _DEBUG  // LightView.cpp �еĵ��԰汾
inline CLightDoc* CLightView::GetDocument() const
   { return reinterpret_cast<CLightDoc*>(m_pDocument); }
#endif

