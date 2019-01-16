// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Score.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog �Ի���

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDialog::IDD, pParent)
	, AddNumber(_T(""))
	, AddName(_T(""))
	, AddScore(_T(""))
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, AddNumber);
	DDX_Text(pDX, IDC_EDIT2, AddName);
	DDX_Text(pDX, IDC_EDIT3, AddScore);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyDialog ��Ϣ�������
