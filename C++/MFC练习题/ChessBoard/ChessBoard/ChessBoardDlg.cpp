
// ChessBoardDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChessBoard.h"
#include "ChessBoardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_LBUTTONDOWN()
//	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CChessBoardDlg �Ի���




CChessBoardDlg::CChessBoardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChessBoardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChessBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChessBoardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_WHITE, &CChessBoardDlg::OnBnClickedWhite)
	ON_BN_CLICKED(IDC_BLACK, &CChessBoardDlg::OnBnClickedBlack)
END_MESSAGE_MAP()


// CChessBoardDlg ��Ϣ�������

BOOL CChessBoardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	blackNum = 0;
	whiteNum = 0;
	flag = false;
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			blank8x8[i][j] = BLANK;
		}
	}
	blank8x8[3][3] = blank8x8[4][4] = WHITE;
	blank8x8[4][3] = blank8x8[3][4] = BLACK;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CChessBoardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChessBoardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		DrawChessBoard();
		DrawChess();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChessBoardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChessBoardDlg::DrawChessBoard(){
	CClientDC dc(this);
	CPen pen(0,1,RGB(0,0,0));
	dc.SelectObject(pen);

	for(int i = 0 ; i < 9 ; i++){
		dc.MoveTo(20,20+30*i);
		dc.LineTo(20+30*8,20+30*i);
		dc.MoveTo(20+30*i,20);
		dc.LineTo(20+30*i,20+30*8);
	}
}

void CChessBoardDlg::DrawChess(){
	CClientDC dc(this);
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(blank8x8[i][j] == BLACK){
				CBrush brushBlack(RGB(0,0,0));
				dc.SelectObject(brushBlack);
				dc.Ellipse(20+30*i,20+30*j,50+30*i,50+30*j);
			}
			else if(blank8x8[i][j] == WHITE){
				CBrush brushWhite(RGB(255,255,255));
				dc.SelectObject(brushWhite);
				dc.Ellipse(20+30*i,20+30*j,50+30*i,50+30*j);
			}
		}
	}
}

bool CChessBoardDlg::CanPlace(int x, int y){
	if(x < 20 || x > 260 || y < 20 || y > 260)
		return false;
	else
		return true;
}

bool CChessBoardDlg::IsOver(int x, int y){
	int count = 1;//��¼���ӵĸ���
	//��ֱ����
	for(int i = 1 ; y - i >= 0 ; i++){
		if(blank8x8[x][y-i] == currChess)
			count++;
		else
			break;
	}
	for(int i = 1 ; y + i <= 8 ; i++){
		if(blank8x8[x][y+i] == currChess)
			count++;
		else
			break;
	}
	if(count >= 5)
		return true;
	else
		count = 1;

	//ˮƽ����
	for(int i = 1 ; x - i >= 0 ; i++){
		if(blank8x8[x-i][y] == currChess)
			count++;
		else
			break;
	}
	for(int i = 1 ; x + i <= 8 ; i++){
		if(blank8x8[x+i][y] == currChess)
			count++;
		else
			break;
	}
	if(count >= 5)
		return true;
	else
		count = 1;

	//���ϵ���������б
	for(int i = 1 ; x - i >= 0 && y - i >= 0; i++){
		if(blank8x8[x-i][y-i] == currChess)
			count++;
		else
			break;
	}
	for(int i = 1 ; y + i <= 8 && x + i <= 8 ; i++){
		if(blank8x8[x+i][y+i] == currChess)
			count++;
		else
			break;
	}
	if(count >= 5)
		return true;
	else
		count = 1;

	//���ϵ���������б
	for(int i = 1 ; x + i <= 8 && y - i >= 0; i++){
		if(blank8x8[x+i][y-i] == currChess)
			count++;
		else
			break;
	}
	for(int i = 1 ; y + i <= 8 && x - i >= 0 ; i++){
		if(blank8x8[x+i][y+i] == currChess)
			count++;
		else
			break;
	}
	if(count >= 5)
		return true;
	else
		count = 1;
	return false;
}


void CChessBoardDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int x = (point.x - 20) / 30;
	int y = (point.y - 20) / 30;
	if(flag){
		MessageBox("�˾��Ѿ�����");
		return;
	}
	if(currChess == WHITE){
		MessageBox("����Ӧ��������");
		return;
	}
	else{
		currChess = WHITE;
		if(CanPlace(point.x,point.y)){
			blank8x8[x][y] = currChess;
		}
		else{
			MessageBox("����������ѡ��");
		}
		this->Invalidate();
		if(IsOver(x,y)){
			MessageBox("����ʤ��");
			flag = true;
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CChessBoardDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int x = (point.x - 20) / 30;
	int y = (point.y - 20) / 30;
	if(flag){
		MessageBox("�˾��Ѿ�����");
		return;
	}
	if(currChess == BLACK){
		MessageBox("����Ӧ��������");
		return;
	}
	else{
		currChess = BLACK;
		if(CanPlace(point.x,point.y)){
			blank8x8[x][y] = currChess;
		}
		else{
			MessageBox("����������ѡ��");
		}
		this->Invalidate();
		if(IsOver(x,y)){
			MessageBox("����ʤ��");
			flag = true;
		}
	}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CChessBoardDlg::OnBnClickedWhite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	currChess = BLACK;
}


void CChessBoardDlg::OnBnClickedBlack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	currChess = WHITE;
}
