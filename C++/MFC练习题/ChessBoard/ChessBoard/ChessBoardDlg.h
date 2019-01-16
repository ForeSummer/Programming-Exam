
// ChessBoardDlg.h : ͷ�ļ�
//

#pragma once


// CChessBoardDlg �Ի���
class CChessBoardDlg : public CDialogEx
{
// ����
public:
	CChessBoardDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHESSBOARD_DIALOG };
	enum BlankState{BLACK,WHITE,BLANK};
	BlankState blank8x8[8][8];
	BlankState currChess;
	int blackNum;
	int whiteNum;
	bool flag;

	void DrawChessBoard();
	void DrawChess();
	bool CanPlace(int x, int y);
	bool IsOver(int x, int y);

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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedWhite();
	afx_msg void OnBnClickedBlack();
};
