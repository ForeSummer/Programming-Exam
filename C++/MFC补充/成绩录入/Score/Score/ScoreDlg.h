
// ScoreDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CScoreDlg �Ի���
class CScoreDlg : public CDialogEx
{
// ����
public:
	CScoreDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SCORE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
	void readAndShowTxtFile(CString fileName);
	void readAndShowExcelFile(CString FileName);
	void writeTxtFile(CString FileName);
	void writeExcelFile(CString FileName);
	bool judge(CString studentNumber);
	CString GetExcelDriver();
	CListCtrl TotalList;
	CString Number;
	CString Name;
	CString Score;
	CButton In;
	CButton Out;
	CButton Add;
	CButton Delete;
	CButton Exit;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);
};
