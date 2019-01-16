
// Calculator1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator1.h"
#include "Calculator1Dlg.h"
#include "afxdialogex.h"
#include <math.h>
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


// CCalculator1Dlg �Ի���




CCalculator1Dlg::CCalculator1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator1Dlg::IDD, pParent)
	, parameter(0)
	, isPoint(false)
	, sumPoint(0)
	, result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculator1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, parameter);
}

BEGIN_MESSAGE_MAP(CCalculator1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ONE, &CCalculator1Dlg::OnBnClickedOne)
	ON_BN_CLICKED(IDC_TWO, &CCalculator1Dlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_THREE, &CCalculator1Dlg::OnBnClickedThree)
	ON_BN_CLICKED(IDC_FOUR, &CCalculator1Dlg::OnBnClickedFour)
	ON_BN_CLICKED(IDC_FIVE, &CCalculator1Dlg::OnBnClickedFive)
	ON_BN_CLICKED(IDC_SEX, &CCalculator1Dlg::OnBnClickedSex)
	ON_BN_CLICKED(IDC_SEVEN, &CCalculator1Dlg::OnBnClickedSeven)
	ON_BN_CLICKED(IDC_EIGHT, &CCalculator1Dlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_NINE, &CCalculator1Dlg::OnBnClickedNine)
	ON_BN_CLICKED(IDC_ZERO, &CCalculator1Dlg::OnBnClickedZero)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculator1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculator1Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_ADD, &CCalculator1Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_REDUCE, &CCalculator1Dlg::OnBnClickedReduce)
	ON_BN_CLICKED(IDC_MUITIPLE, &CCalculator1Dlg::OnBnClickedMuitiple)
	ON_BN_CLICKED(IDC_DIVISION, &CCalculator1Dlg::OnBnClickedDivision)
	ON_BN_CLICKED(IDC_CALCULATE, &CCalculator1Dlg::OnBnClickedCalculate)
	ON_BN_CLICKED(IDC_CLEAR, &CCalculator1Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CCalculator1Dlg ��Ϣ�������

BOOL CCalculator1Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculator1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculator1Dlg::OnPaint()
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
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculator1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculator1Dlg::OnBnClickedOne()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 1;
	}
	else{
		parameter = parameter + 1 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedTwo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 2;
	}
	else{
		parameter = parameter + 2 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedThree()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 3;
	}
	else{
		parameter = parameter + 3 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedFour()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 4;
	}
	else{
		parameter = parameter + 4 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedFive()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 5;
	}
	else{
		parameter = parameter + 5 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedSex()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 6;
	}
	else{
		parameter = parameter + 6 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedSeven()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 7;
	}
	else{
		parameter = parameter + 7 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedEight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 8;
	}
	else{
		parameter = parameter + 8 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedNine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 9;
	}
	else{
		parameter = parameter + 9 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedZero()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(!isPoint){
		parameter = parameter * 10 + 0;
	}
	else{
		parameter = parameter + 0 / pow(10.0,sumPoint);
		sumPoint++;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	isPoint = true;
	sumPoint = 1;
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	parameter = -parameter;
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = parameter;
	parameter = 0;
	isPoint = false;
	sumPoint = 0;
	opera = '+';
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedReduce()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = parameter;
	parameter = 0;
	isPoint = false;
	sumPoint = 0;
	opera = '-';
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedMuitiple()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = parameter;
	parameter = 0;
	isPoint = false;
	sumPoint = 0;
	opera = 'x';
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedDivision()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = parameter;
	parameter = 0;
	isPoint = false;
	sumPoint = 0;
	opera = '/';
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedCalculate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	switch(opera){
	case '+':
		result += parameter;
		parameter = result;
		break;
	case '-':
		result -= parameter;
		parameter = result;
		break;
	case 'x':
		result *= parameter;
		parameter = result;
		break;
	case '/':
		if(parameter){
			result /= parameter;
			parameter = result;
		}
		else{
			parameter = 0;
			MessageBox("��������Ϊ0");
		}
		break;
	}
	UpdateData(false);
}


void CCalculator1Dlg::OnBnClickedClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	parameter = 0;
	result = 0;
	isPoint = false;
	sumPoint = 0;
	UpdateData(false);
}
