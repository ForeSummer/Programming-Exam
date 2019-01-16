
// ColorBoardDoc.cpp : CColorBoardDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ColorBoard.h"
#endif

#include "ColorBoardDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CColorBoardDoc

IMPLEMENT_DYNCREATE(CColorBoardDoc, CDocument)

BEGIN_MESSAGE_MAP(CColorBoardDoc, CDocument)
END_MESSAGE_MAP()


// CColorBoardDoc ����/����

CColorBoardDoc::CColorBoardDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CColorBoardDoc::~CColorBoardDoc()
{
}

BOOL CColorBoardDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CColorBoardDoc ���л�

void CColorBoardDoc::Serialize(CArchive& ar)
{
	
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar.WriteCount(geometries.GetCount());
		for(int i = 0 ; i < geometries.GetCount() ; i++){
			ar<<geometries[i];
		}
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		int count = ar.ReadCount();
		CObject* pObj;
		for(int i = 0 ; i < count ; i++){
			ar>>pObj;
			if(pObj)
				geometries.Add(pObj);
		}
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CColorBoardDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CColorBoardDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CColorBoardDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CColorBoardDoc ���

#ifdef _DEBUG
void CColorBoardDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CColorBoardDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CColorBoardDoc ����
