
// Calculator1Dlg.h : ͷ�ļ�
//

#pragma once


// CCalculator1Dlg �Ի���
class CCalculator1Dlg : public CDialogEx
{
// ����
public:
	CCalculator1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR1_DIALOG };

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
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedSex();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedNine();
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedReduce();
	afx_msg void OnBnClickedMuitiple();
	afx_msg void OnBnClickedDivision();
	afx_msg void OnBnClickedCalculate();
	afx_msg void OnBnClickedClear();
	double parameter;
	double result;
	bool isPoint;
	int sumPoint;
	char opera;
};
