
// �˻ʺ�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�˻ʺ�.h"
#include "�˻ʺ�Dlg.h"
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
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�˻ʺ�Dlg �Ի���




C�˻ʺ�Dlg::C�˻ʺ�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�˻ʺ�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�˻ʺ�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�˻ʺ�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// C�˻ʺ�Dlg ��Ϣ�������

BOOL C�˻ʺ�Dlg::OnInitDialog()
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
	for(int i = 0 ; i < 8 ; i ++){
		for(int j = 0 ; j < 8 ; j++){
			chesses[i][j] = BLANK;
		}
	}
	align = 20;
	width = 30;
	count = 0;
	//chesses[3][0]=chesses[4][0]=BLACK;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�˻ʺ�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�˻ʺ�Dlg::OnPaint()
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
		drawChessBoard();
		drawChess();
		if(isOver())
			MessageBox("win");
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�˻ʺ�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C�˻ʺ�Dlg::drawChessBoard(){
	CClientDC dc(this);
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	dc.SelectObject(pen);
	for(int i = 0 ; i < 9 ; i++){
		dc.MoveTo(align,align+width*i);
		dc.LineTo(align+width*8,align+width*i);
		dc.MoveTo(align+width*i,align);
		dc.LineTo(align+width*i,align+width*8);
	}
}
void C�˻ʺ�Dlg::drawChess(){
	CClientDC dc(this);
	CBrush brush_black(RGB(0,0,0));
	CBrush brush_red(RGB(255,0,0));
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(chesses[j][i] == BLACK){
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

bool C�˻ʺ�Dlg::isOver(){
	int num = 0;
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(chesses[j][i] == BLACK)
				num++;
		}
	}
	if(num == 8)
		return true;
	else
		return false;
}

bool C�˻ʺ�Dlg::canPlace(int x,int y){
	POSTION pos;
	//��
	for(int i = 0 ; i < y ; i++){
		if(chesses[x][i] == BLACK)
		{
			pos.x = x;
			pos.y = i;
			red_vec.push_back(pos);
		
		}
	}
	//��
	for(int i = 7 ; i > y ; i--){
		if(chesses[x][i] == BLACK)
		{
			pos.x = x;
			pos.y = i;
			red_vec.push_back(pos);
		
		}
	}
	//��
	for(int i = 0 ; i < x ; i++){
		if(chesses[i][y] == BLACK)
		{
			pos.x = i;
			pos.y = y;
			red_vec.push_back(pos);
			
		}
	}
	//��
	for(int i = 7 ; i > x ; i--){
		if(chesses[i][y] == BLACK)
		{
			pos.x = i;
			pos.y = y;
			red_vec.push_back(pos);
			
		}
	}
	//����
	if(x > y){
		for(int i = 0 ; i < y ; i++){
			if(chesses[x-y+i][i] == BLACK)
			{
				pos.x = x-y+i;
				pos.y = i;
				red_vec.push_back(pos);
				
			}
		}
	}
	else{
		for(int i = 0 ; i < x ; i++){
			if(chesses[i][y-x+i] == BLACK)
			{
				pos.x = i;
				pos.y = y-x+i;
				red_vec.push_back(pos);
				
			}
		}
	}
	//����
	if((x+y)<=7){
		for(int i = 0 ; i < x ; i++){
			if(chesses[i][x+y-i] == BLACK)
			{
				pos.x = i;
				pos.y = x+y-i;
				red_vec.push_back(pos);
				
			}
		}
	}
	else{
		for(int i = 7 ; i > y ; i--){
			if(chesses[x+y-i][i] == BLACK)
			{
				pos.x = x+y-i;
				pos.y = i;
				red_vec.push_back(pos);
				
			}
		}
	}
	//����
	if((x+y)<=7){
		for(int i = 0 ; i < y ; i++){
			if(chesses[x+y-i][i] == BLACK)
			{
				pos.x = x+y-i;
				pos.y = i;
				red_vec.push_back(pos);
				
			}
		}
	}
	else{
		for(int i = 7 ; i > x ; i--){
			if(chesses[i][x+y-i] == BLACK)
			{
				pos.x = i;
				pos.y = x+y-i;
				red_vec.push_back(pos);
				
			}
		}
	}
	//����
	if(x > y){
		for(int i = 7 ; i > x ; i--){
			if(chesses[i][i-(x-y)] == BLACK)
			{
				pos.x = i;
				pos.y = i-(x-y);
				red_vec.push_back(pos);
				
			}
		}
	}
	else{
		for(int i = 7 ; i > x ; i--){
			if(chesses[i-(y-x)][i] == BLACK)
			{
				pos.x = i-(y-x);
				pos.y = i;
				red_vec.push_back(pos);
				
			}
		}
	}
	int size = red_vec.size();
	if(red_vec.size()!=0)
		return false;
	else
		return true;
}
bool C�˻ʺ�Dlg::isLose(int x,int y){
	for(int i = 0 ; i < 7 ; i++){
		if(canPlace(i,y))
			return false;
	}
	return true;
}
void C�˻ʺ�Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	for(int i = 0 ; i < red_vec.size() ; i++){
		chesses[red_vec[i].x][red_vec[i].y] = BLACK;
	}
	Invalidate();
	red_vec.clear();

	int x = (point.x-align)/width;
	int y = (point.y-align)/width;

	if(isLose(x,y)){
		MessageBox("Lose");
		return;
	}
	
	if(canPlace(x,y)){
		chesses[x][y] = BLACK;
	}
	else{
		for(int i = 0 ; i < red_vec.size() ; i++){
			chesses[red_vec[i].x][red_vec[i].y] = RED;
		}
	}
	Invalidate();

	
	
	CDialogEx::OnLButtonDown(nFlags, point);
}
