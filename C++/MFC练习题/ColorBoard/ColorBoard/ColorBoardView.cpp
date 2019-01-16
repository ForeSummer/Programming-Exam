
// ColorBoardView.cpp : CColorBoardView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ColorBoard.h"
#endif

#include "ColorBoardDoc.h"
#include "ColorBoardView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CColorBoardView

IMPLEMENT_DYNCREATE(CColorBoardView, CView)

BEGIN_MESSAGE_MAP(CColorBoardView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CColorBoardView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CColorBoardView::OnLine)
	ON_COMMAND(ID_CIRCLE, &CColorBoardView::OnCircle)
	ON_COMMAND(ID_RANCTANGLE, &CColorBoardView::OnRanctangle)
	ON_COMMAND(ID_COLOR, &CColorBoardView::OnColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_UNDO, &CColorBoardView::OnUndo)
	ON_COMMAND(ID_REDO, &CColorBoardView::OnRedo)
	ON_COMMAND(ID_CLEAR, &CColorBoardView::OnClear)
END_MESSAGE_MAP()

// CColorBoardView ����/����

CColorBoardView::CColorBoardView()
{
	// TODO: �ڴ˴���ӹ������
	isMouseDown = false;
}

CColorBoardView::~CColorBoardView()
{
}

BOOL CColorBoardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CColorBoardView ����

void CColorBoardView::OnDraw(CDC* pDC)
{
	CColorBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CObArray& geometries = pDoc->geometries;
	for(int i = 0 ; i < geometries.GetCount() ; i++){
		Geometry* geometry = (Geometry*)geometries[i];
		geometry->Draw(pDC);
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CColorBoardView ��ӡ


void CColorBoardView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CColorBoardView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CColorBoardView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CColorBoardView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CColorBoardView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CColorBoardView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CColorBoardView ���

#ifdef _DEBUG
void CColorBoardView::AssertValid() const
{
	CView::AssertValid();
}

void CColorBoardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CColorBoardDoc* CColorBoardView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CColorBoardDoc)));
	return (CColorBoardDoc*)m_pDocument;
}
#endif //_DEBUG


// CColorBoardView ��Ϣ�������


void CColorBoardView::OnLine()
{
	// TODO: �ڴ���������������
	curType = LINE;
}


void CColorBoardView::OnCircle()
{
	// TODO: �ڴ���������������
	curType = CIRCLE;
}


void CColorBoardView::OnRanctangle()
{
	// TODO: �ڴ���������������
	curType = RANTANGLE;
}


void CColorBoardView::OnColor()
{
	// TODO: �ڴ���������������
	CColorDialog dig;
	if(dig.DoModal() == IDOK){
		curColor = dig.GetColor();
	}
}

void CColorBoardView::addGeometry(){

	CColorBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	switch(curType){
	case LINE:
		curGeometry = new Line();
		pDoc->geometries.Add(curGeometry);
		break;
	case CIRCLE:
		curGeometry = new Circle();
		pDoc->geometries.Add(curGeometry);
		break;
	case RANTANGLE:
		curGeometry = new Rectan();
		pDoc->geometries.Add(curGeometry);
		break;
	}
}

void CColorBoardView::setCurGeometry(CPoint start,CPoint end){
	if(curGeometry){
		switch(curType){
		case LINE:
			((Line*)curGeometry)->start = start;
			((Line*)curGeometry)->end = end;
			((Line*)curGeometry)->pen_color = curColor;
			break;
		case CIRCLE:
			((Circle*)curGeometry)->start = start;
			((Circle*)curGeometry)->end = end;
			((Circle*)curGeometry)->pen_color = curColor;
			break;
		case RANTANGLE:
			((Rectan*)curGeometry)->start = start;
			((Rectan*)curGeometry)->end = end;
			((Rectan*)curGeometry)->pen_color = curColor;
		}
	}
	Invalidate(true);
}

void CColorBoardView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	isMouseDown = true;
	start = point;
	addGeometry();
	CView::OnLButtonDown(nFlags, point);
}


void CColorBoardView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	isMouseDown = false;
	CView::OnLButtonUp(nFlags, point);
}


void CColorBoardView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(isMouseDown){
		setCurGeometry(start,point);
	}

	CView::OnMouseMove(nFlags, point);
}


void CColorBoardView::OnUndo()
{
	// TODO: �ڴ���������������
	CColorBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for(int i = 0 ; i < pDoc->geometries.GetCount() ; i++){
		geometries_copy.Add(pDoc->geometries.GetAt(i));
	}
	pDoc->geometries.RemoveAt(pDoc->geometries.GetCount()-1);
	Invalidate(TRUE);
}


void CColorBoardView::OnRedo()
{
	// TODO: �ڴ���������������
	CColorBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->geometries.RemoveAll();
	for(int i = 0 ; i < geometries_copy.GetCount() ; i++){
		pDoc->geometries.Add(geometries_copy.GetAt(i));
	}
	Invalidate(TRUE);


}


void CColorBoardView::OnClear()
{
	// TODO: �ڴ���������������
	CColorBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->geometries.RemoveAll();
	Invalidate(TRUE);
}
