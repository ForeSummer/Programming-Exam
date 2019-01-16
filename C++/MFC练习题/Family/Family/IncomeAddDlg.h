#pragma once
#include "afxwin.h"
#include "FamilyDlg.h"


// IncomeAddDlg �Ի���

class IncomeAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(IncomeAddDlg)

public:
	IncomeAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~IncomeAddDlg();

// �Ի�������
	enum { IDD = IDD_IN_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString in_add_name;
	CString in_add_come;
	double in_add_money;
	CComboBox in_add_year_ctl;
	CComboBox in_add_month_ctl;
	CComboBox in_add_day_ctl;
	CString in_add_year;
	CString in_add_month;
	CString in_add_day;
	virtual BOOL OnInitDialog();
	void inputData(vector<income> in,int index);
};
