
// PingTuDlg.h : ͷ�ļ�
//

#pragma once
#include <vector>
using namespace std;

// CPingTuDlg �Ի���
class CPingTuDlg : public CDialogEx
{
// ����
public:
	CPingTuDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PINGTU_DIALOG };
	int align;
	int width;
	
	int chesses[4][4];
	int empty_x;
	int empty_y;
	
	void drawChessBoard();
	void drawChess();
	void initBoard();
	bool ifChangeLeft(int x,int y);
	bool ifChangeRight(int x,int y);
	bool ifChangeUp(int x,int y);
	bool ifChangeDown(int x,int y);
	void change(int x,int y);
	bool isOver();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
