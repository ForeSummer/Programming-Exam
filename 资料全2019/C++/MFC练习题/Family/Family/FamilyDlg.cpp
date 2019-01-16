
// FamilyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Family.h"
#include "FamilyDlg.h"
#include "afxdialogex.h"
#include <iomanip>
#include <algorithm>
#include "IncomeAddDlg.h"

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


// CFamilyDlg �Ի���




CFamilyDlg::CFamilyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFamilyDlg::IDD, pParent)
	, in_start_year(_T(""))
	, in_start_month(_T(""))
	, in_start_day(_T(""))
	, in_end_year(_T(""))
	, in_end_month(_T(""))
	, in_end_day(_T(""))
	, total_income(0)
	, in_name_search(_T(""))
	, in_come_search(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFamilyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_IN_LIST, IN_LIST);
	DDX_Text(pDX, IDC_IN_START_YEAR, in_start_year);
	DDX_Text(pDX, IDC_IN_START_MONTH, in_start_month);
	DDX_Text(pDX, IDC_IN_START_DAY, in_start_day);
	DDX_Text(pDX, IDC_IN_END_YEAR, in_end_year);
	DDX_Text(pDX, IDC_IN_END_MONTH, in_end_month);
	DDX_Text(pDX, IDC_IN_END_DAY, in_end_day);
	DDX_Text(pDX, IDC_IN_TOTAL, total_income);
	DDX_Text(pDX, IDC_IN_NAME_SEARCH, in_name_search);
	DDX_Text(pDX, IDC_IN_COME_SEARCH, in_come_search);
	DDX_Control(pDX, IDC_IN_SEARCH_LIST, IN_SEARCH_LIST);
}

BEGIN_MESSAGE_MAP(CFamilyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IN_ADD, &CFamilyDlg::OnBnClickedInAdd)
	ON_BN_CLICKED(IDC_IN_MODIFY, &CFamilyDlg::OnBnClickedInModify)
	ON_BN_CLICKED(IDC_IN_DELETE, &CFamilyDlg::OnBnClickedInDelete)
	ON_BN_CLICKED(IDC_IN_SEARCH, &CFamilyDlg::OnBnClickedInSearch)
	ON_BN_CLICKED(IDC_INCOME_SORT, &CFamilyDlg::OnBnClickedIncomeSort)
	ON_BN_CLICKED(IDC_IN_DATE_SORT, &CFamilyDlg::OnBnClickedInDateSort)
	ON_BN_CLICKED(IDC_IN_SERACH, &CFamilyDlg::OnBnClickedInSerach)
END_MESSAGE_MAP()


// CFamilyDlg ��Ϣ�������

BOOL CFamilyDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ����
	CString str;
	str.Format("%20s%20s%20s%20s","name","come","date","money");
	IN_LIST.AddString(str);
	IN_SEARCH_LIST.AddString(str);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFamilyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFamilyDlg::OnPaint()
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
HCURSOR CFamilyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CFamilyDlg::OnBnClickedInAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������
	IncomeAddDlg in_add_dlg = new IncomeAddDlg();
	CString str;
	if(IDOK == in_add_dlg.DoModal()){
		income in;
		in.name = in_add_dlg.in_add_name;
		in.come = in_add_dlg.in_add_come;
		in.year = in_add_dlg.in_add_year;
		in.month = in_add_dlg.in_add_month;
		in.day = in_add_dlg.in_add_day;
		in.money = in_add_dlg.in_add_money;
		income_vec.push_back(in);
		CString date;
		date.Format("%s-%s-%s",in_add_dlg.in_add_year,in_add_dlg.in_add_month,in_add_dlg.in_add_day);
		CString money;
		money.Format("%1f",in_add_dlg.in_add_money);
		str.Format("%20s%20s%20s%20s",in_add_dlg.in_add_name,in_add_dlg.in_add_come,date,money);
		IN_LIST.AddString(str);
	}
}


void CFamilyDlg::OnBnClickedInModify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = IN_LIST.GetCurSel();
	IncomeAddDlg in_modify_dlg = new IncomeAddDlg();

	in_modify_dlg.inputData(income_vec,index);
	in_modify_dlg.DoModal();	
	income_vec[index-1].name = in_modify_dlg.in_add_name;
	income_vec[index-1].come = in_modify_dlg.in_add_come;
	income_vec[index-1].year = in_modify_dlg.in_add_year;
	income_vec[index-1].month = in_modify_dlg.in_add_month;
	income_vec[index-1].day = in_modify_dlg.in_add_day;
	income_vec[index-1].money = in_modify_dlg.in_add_money;
	CString date;
	date.Format("%s-%s-%s",in_modify_dlg.in_add_year,in_modify_dlg.in_add_month,in_modify_dlg.in_add_day);
	CString money;
	money.Format("%f",in_modify_dlg.in_add_money);
	CString str;
	str.Format("%20s%20s%20s%20s",in_modify_dlg.in_add_name,in_modify_dlg.in_add_come,date,money);
	IN_LIST.DeleteString(index);
	IN_LIST.InsertString(index,str);
}


void CFamilyDlg::OnBnClickedInDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = IN_LIST.GetCurSel();
	vector<income>::iterator it;
	int count = 0;
	for(it = income_vec.begin() ; it < income_vec.end() ; it++){
		if(index - 1 == count){
			income_vec.erase(it);
			break;
		}
		count++;
	}
	IN_LIST.DeleteString(index);
}

bool CFamilyDlg::IsBeforeDate(CString curyear,CString curmonth,
	CString curday,CString _year,CString _month,CString _day){
	int cur_year = _ttoi(curyear);
	int cur_month = _ttoi(curmonth);
	int cur_day = _ttoi(curday);
	int year = _ttoi(_year);
	int month = _ttoi(_month);
	int day = _ttoi(_day);

	if(cur_year < year)
		return true;
	else if(cur_year == year && cur_month < month)
		return true;
	else if(cur_year == year && cur_month == month && cur_day < day)
		return true;
	else
		return false;
}

void CFamilyDlg::OnBnClickedInSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	total_income = 0;
	for(int i = 0 ; i < income_vec.size() ; i++){
		CString year,month,day;
		year.Format("%s",income_vec[i].year.c_str());
		month.Format("%s",income_vec[i].month.c_str());
		day.Format("%s",income_vec[i].day.c_str());
		if(IsBeforeDate(in_start_year,in_start_month,in_start_day,year,month,day)
			&&IsBeforeDate(year,month,day,in_end_year,in_end_month,in_end_day)){
				total_income += income_vec[i].money;
		}
	}
	UpdateData(FALSE);
	return;
}


void CFamilyDlg::OnBnClickedIncomeSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort(income_vec.begin(),income_vec.end(),compareIncome);
	for(int i = 0 ; i < income_vec.size() ; i++){
		CString date;
		date.Format("%s-%s-%s",income_vec[i].year.c_str(),income_vec[i].month.c_str(),income_vec[i].day.c_str());
		CString money;
		money.Format("%f",income_vec[i].money);
		CString str;
		str.Format("%20s%20s%20s%20s",income_vec[i].name.c_str(),income_vec[i].come.c_str(),date,money);
		IN_LIST.DeleteString(i+1);
		IN_LIST.InsertString(i+1,str);
	}
}


void CFamilyDlg::OnBnClickedInDateSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort(income_vec.begin(),income_vec.end(),compareDate);
	for(int i = 0 ; i < income_vec.size() ; i++){
		CString date;
		date.Format("%s-%s-%s",income_vec[i].year.c_str(),income_vec[i].month.c_str(),income_vec[i].day.c_str());
		CString money;
		money.Format("%f",income_vec[i].money);
		CString str;
		str.Format("%20s%20s%20s%20s",income_vec[i].name.c_str(),income_vec[i].come.c_str(),date,money);
		IN_LIST.DeleteString(i+1);
		IN_LIST.InsertString(i+1,str);
	}
}


void CFamilyDlg::OnBnClickedInSerach()
{
	UpdateData(TRUE);
	for(int i = 0 ; i < income_search_vec.size() ; i++){
		IN_SEARCH_LIST.DeleteString(1);
	}
	income_search_vec.clear();
	for(int i = 0 ; i < income_vec.size() ; i++){
		string name = in_name_search.GetBuffer(0);
		string come = in_come_search.GetBuffer(0);
		if(name == income_vec[i].name || come == income_vec[i].come)
			income_search_vec.push_back(income_vec[i]);
	}
	CString str;
	for(int i = 0 ; i < income_search_vec.size() ; i++){
		CString date;
		date.Format("%s-%s-%s",income_search_vec[i].year.c_str(),income_search_vec[i].month.c_str(),income_search_vec[i].day.c_str());
		CString money;
		money.Format("%f",income_search_vec[i].money);
		CString str;
		str.Format("%20s%20s%20s%20s",income_search_vec[i].name.c_str(),income_search_vec[i].come.c_str(),date,money);
		IN_SEARCH_LIST.AddString(str);
	}
}
