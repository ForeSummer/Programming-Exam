
// �˻ʺ�Dlg.h : ͷ�ļ�
//

#pragma once
#include <vector>
using namespace std;

struct POSTION{
	int x;
	int y;
};

// C�˻ʺ�Dlg �Ի���
class C�˻ʺ�Dlg : public CDialogEx
{
// ����
public:
	C�˻ʺ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };
	enum CHESS{BLANK,BLACK,RED};
	CHESS chesses[8][8];
	int align;
	int width;
	int count;
	
	vector<POSTION> red_vec;
	
	void drawChessBoard();
	void drawChess();
	bool isOver();
	bool isLose(int x,int y);
	bool canPlace(int x,int y);
	

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
