
// CompetitionDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCompetitionDlg �Ի���
class CCompetitionDlg : public CDialogEx
{
// ����
public:
	CCompetitionDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COMPETITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Blue;
	afx_msg void OnLbnSelchangeList1();
	CString Red;
	CString Who;
	CButton Start;
	CButton Exit;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEnChangeEdit3();
	public:
	bool blueOrRed;
	bool Begin;
	int judge[8][8];
	int numberRed[8][8];
	int numberBlue[8][8];
	int BlueScore;
	int RedScore;
	void text();
	bool Gameover();
	afx_msg void OnBnClickedButton2();
};
