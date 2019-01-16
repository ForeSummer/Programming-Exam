
// OthelloDlg.h : ͷ�ļ�
//

#pragma once


// COthelloDlg �Ի���
class COthelloDlg : public CDialogEx
{
// ����
public:
	COthelloDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OTHELLO_DIALOG };
	enum CHESS{BLANK,BLACK,WHITE};
	CHESS chesses[8][8];
	int white;
	int black;
	CHESS curChess;
	int align;
	int width;

	void drawChessBoard();
	void drawChess();
	bool isOver();
	void tellFinal();
	bool ifChangeUp(int x,int y);
	bool ifChangeDown(int x,int y);
	bool ifChangeLeft(int x,int y);
	bool ifChangeRight(int x,int y);
	bool ifChangeUpLeft(int x,int y);
	bool ifChangeUpRight(int x,int y);
	bool ifChangeDownLeft(int x,int y);
	bool ifChangeDownRight(int x,int y);
	void changeUp(int x,int y);
	void changeDown(int x,int y);
	void changeLeft(int x,int y);
	void changeRight(int x,int y);
	void changeUpLeft(int x,int y);
	void changeUpRight(int x,int y);
	void changeDownLeft(int x,int y);
	void changeDownRight(int x,int y);

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
