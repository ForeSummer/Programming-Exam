
// LightView.cpp : CLightView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Light.h"
#endif

#include "LightDoc.h"
#include "LightView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLightView

IMPLEMENT_DYNCREATE(CLightView, CFormView)

BEGIN_MESSAGE_MAP(CLightView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_GENERATE_CHESS, &CLightView::OnBnClickedGenerateChess)
	ON_BN_CLICKED(IDC_SAVE, &CLightView::OnBnClickedSave)
	ON_BN_CLICKED(IDC_OPEN, &CLightView::OnBnClickedOpen)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_CLEAR, &CLightView::OnBnClickedClear)
END_MESSAGE_MAP()

// CLightView ����/����

CLightView::CLightView()
	: CFormView(CLightView::IDD)
	, m(0)
	, n(0)
	, r(0)
{
	// TODO: �ڴ˴���ӹ������
	align = 20;
	width = 30;
	
}

CLightView::~CLightView()
{
}

void CLightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_M, m);
	DDX_Text(pDX, IDC_N, n);
	DDX_Text(pDX, IDC_P, r);
}

BOOL CLightView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CLightView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CLightView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLightView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLightView ���

#ifdef _DEBUG
void CLightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLightDoc* CLightView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLightDoc)));
	return (CLightDoc*)m_pDocument;
}
#endif //_DEBUG


// CLightView ��Ϣ�������

void CLightView::drawChessBoard(){
	CClientDC dc(this);
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	dc.SelectObject(pen);
	for(int i = 0 ; i <= m ; i++){
		dc.MoveTo(align,align+width*i);
		dc.LineTo(align+width*n,align+width*i);
	}
	for(int i = 0 ; i <= n ; i++){
		dc.MoveTo(align+width*i,align);
		dc.LineTo(align+width*i,align+width*m);
	}
}

void CLightView::drawChess(){
	CClientDC dc(this);
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CBrush brush_black(RGB(0,0,0));
	CBrush brush_red(RGB(255,0,0));
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0; j < n ; j++){
			if(chesses[j][i] == MIRROR_0){
				dc.SelectObject(pen);
				dc.MoveTo(align+width*j,align+width*i+width/2);
				dc.LineTo(align+width*(j+1),align+width*i+width/2);
			}
			else if(chesses[j][i] == MIRROR_45){
				dc.SelectObject(pen);
				dc.MoveTo(align+width*j,align+width*i);
				dc.LineTo(align+width*(j+1),align+width*(i+1));
			}
			else if(chesses[j][i] == MIRROR_90){
				dc.SelectObject(pen);
				dc.MoveTo(align+width*j+width/2,align+width*i);
				dc.LineTo(align+width*j+width/2,align+width*(i+1));
			}
			else if(chesses[j][i] == MIRROR_145){
				dc.SelectObject(pen);
				dc.MoveTo(align+width*(j+1),align+width*i);
				dc.LineTo(align+width*j,align+width*(i+1));
			}
			else if(chesses[j][i] == LIGHT){
				dc.SelectObject(brush_black);
				dc.Ellipse(align+width*j,align+width*i,align+width*(j+1),align+width*(i+1));
			}
			else if(chesses[j][i] == RED){
				dc.SelectObject(brush_red);
				dc.Ellipse(align+width*j,align+width*i,align+width*(j+1),align+width*(i+1));
			}
		}
	}
}

void CLightView::initChessBoard(int m, int n){
	chesses = new CHESS*[m];
	for(int i = 0 ; i < n ; i++){
		chesses[i] = new CHESS[n];
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0; j < n ; j++){
			chesses[j][i] = BLANK;
		}
	}
}

void CLightView::OnBnClickedGenerateChess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	initChessBoard(m,n);
	srand(unsigned(time(0)));
	for(int i = 0 ; i < r ; i++){
		int x = rand()%n;
		int y = rand()%m;
		int type = rand()%4;
		if(type == 0){
			chesses[x][y] = MIRROR_0;
		}
		if(type == 1){
			chesses[x][y] = MIRROR_45;
		}
		if(type == 2){
			chesses[x][y] = MIRROR_90;
		}
		if(type == 3){
			chesses[x][y] = MIRROR_145;
		}
	}
	Invalidate();

}


void CLightView::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FILE* f = fopen("state_out.txt","w");
	fprintf(f,"%d,%d",m,n);
	fprintf(f,"\n");
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			fprintf(f,"%d ",chesses[j][i]);
		}
		fprintf(f,"\n");
	}
	fclose(f);
	MessageBox("д���ļ��ɹ���");
}


void CLightView::OnBnClickedOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FILE* f = fopen("state_out.txt","r");
	fscanf(f,"%d,%d",&m,&n);
	initChessBoard(m,n);
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			fscanf(f,"%d",&chesses[j][i]);
		}
	}
	fclose(f);
	Invalidate();
	MessageBox("�ļ���ȡ�ɹ�!");
}


void CLightView::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	drawChessBoard();
	drawChess();
}

bool CLightView::canPlace(int x,int y){
	Position pos;
	//��
	for(int i = 0 ; i < y ; i++){
		if(chesses[x][i] == MIRROR_0){
			for(int j = i+1 ; j < y ; j++){
				if(chesses[x][j] == LIGHT){
					pos.x = x;
					pos.y = j;
					red_vector.push_back(pos);
					
				}
			}
		}
		if(chesses[x][i] == MIRROR_45){
			for(int j = 0 ; j < x ; j++){
				if(chesses[j][i] == LIGHT){
					pos.x = j;
					pos.y = i;
					red_vector.push_back(pos);
			
				}
			}
		}
		if(chesses[x][i] == MIRROR_90){
			for(int j = 0 ; j < y ; j++){
				if(chesses[x][j] == LIGHT){
					pos.x = x;
					pos.y = j;
					red_vector.push_back(pos);
			
				}
			}
		}
		if(chesses[x][i] == MIRROR_145){
			for(int j = m-1 ; j > x ; j--){
				if(chesses[j][i] == LIGHT){
					pos.x = j;
					pos.y = i;
					red_vector.push_back(pos);
		
				}
			}
		}
		if(chesses[x][i] == LIGHT){
			pos.x = x;
			pos.y = i;
			red_vector.push_back(pos);

		}
	}
	//��
	for(int i = m-1 ; i > y ; i--){
		if(chesses[x][i] == MIRROR_0){
			for(int j = i-1 ; j > y ; j--){
				if(chesses[x][j] == LIGHT){
					pos.x = x;
					pos.y = j;
					red_vector.push_back(pos);

				}
			}
		}
		if(chesses[x][i] == MIRROR_45){
			for(int j = n-1 ; j > x ; j--){
				if(chesses[j][i] == LIGHT){
					pos.x = j;
					pos.y = i;
					red_vector.push_back(pos);

				}
			}
		}
		if(chesses[x][i] == MIRROR_90){
			for(int j = m-1 ; j > y ; j--){
				if(chesses[x][j] == LIGHT){
					pos.x = x;
					pos.y = j;
					red_vector.push_back(pos);

				}
			}
		}
		if(chesses[x][i] == MIRROR_145){
			for(int j = 0 ; j < x ; j++){
				if(chesses[j][i] == LIGHT){
					pos.x = j;
					pos.y = i;
					red_vector.push_back(pos);
		
				}
			}
		}
		if(chesses[x][i] == LIGHT){
			pos.x = x;
			pos.y = i;
			red_vector.push_back(pos);

		}
	}
	//��
	for(int i = 0 ; i < x ; i++){
		if(chesses[i][y] == MIRROR_0){
			for(int j = 0 ; j < x ; j++){
				if(chesses[j][y] == LIGHT){
					pos.x = j;
					pos.y = y;
					red_vector.push_back(pos);
				
				}
			}
		}
		if(chesses[i][y] == MIRROR_45){
			for(int j = 0 ; j < y ; j++){
				if(chesses[i][j] == LIGHT){
					pos.x = i;
					pos.y = j;
					red_vector.push_back(pos);
			
				}
			}
		}
		if(chesses[i][y] == MIRROR_90){
			for(int j = i+1 ; j < x ; j++){
				if(chesses[j][y] == LIGHT){
					pos.x = j;
					pos.y = y;
					red_vector.push_back(pos);
				
				}
			}
		}
		if(chesses[i][y] == MIRROR_145){
			for(int j = m-1 ; j > y ; j--){
				if(chesses[i][j] == LIGHT){
					pos.x = i;
					pos.y = j;
					red_vector.push_back(pos);
	
				}
			}
		}
		if(chesses[i][y] == LIGHT){
			pos.x = i;
			pos.y = y;
			red_vector.push_back(pos);

		}
	}
	//��
	for(int i = n-1 ; i > x ; i--){
		if(chesses[i][y] == MIRROR_0){
			for(int j = n-1 ; j > x ; j--){
				if(chesses[j][y] == LIGHT){
					pos.x = j;
					pos.y = y;
					red_vector.push_back(pos);
	
				}
			}
		}
		if(chesses[i][y] == MIRROR_45){
			for(int j = m-1 ; j > y ; j--){
				if(chesses[i][j] == LIGHT){
					pos.x = i;
					pos.y = j;
					red_vector.push_back(pos);
				
				}
			}
		}
		if(chesses[i][y] == MIRROR_90){
			for(int j = i-1 ; j > x ; j--){
				if(chesses[j][y] == LIGHT){
					pos.x = j;
					pos.y = y;
					red_vector.push_back(pos);
			
				}
			}
		}
		if(chesses[i][y] == MIRROR_145){
			for(int j = 0 ; j < y ; j++){
				if(chesses[i][j] == LIGHT){
					pos.x = i;
					pos.y = j;
					red_vector.push_back(pos);
				
				}
			}
		}
		if(chesses[i][y] == LIGHT){
			pos.x = i;
			pos.y = y;
			red_vector.push_back(pos);
		
		}
	}
	if(red_vector.size() != 0)
		return false;
	else
		return true;
}

void CLightView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int x = (point.x - align) / width;
	int y = (point.y - align) / width;

	for(int i = 0 ; i < red_vector.size() ; i++){
		chesses[red_vector[i].x][red_vector[i].y] = LIGHT;
	}
	Invalidate();
	red_vector.clear();

	if(canPlace(x,y)){
		chesses[x][y] = LIGHT;
	}
	else{
		for(int i = 0 ; i < red_vector.size() ; i++){
			chesses[red_vector[i].x][red_vector[i].y] = RED;
		}
	}
	Invalidate();

	CFormView::OnLButtonDown(nFlags, point);
}


void CLightView::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			chesses[j][i] = BLANK;
		}
	}
	Invalidate();
}
