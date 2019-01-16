
// ScoreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Score.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"
#include "conio.h"
#include "MyDialog.h"
#include <afxdb.h>
#include <odbcinst.h>
#include <afxdlgs.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScoreDlg �Ի���



CScoreDlg::CScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScoreDlg::IDD, pParent)
	, Number(_T(""))
	, Name(_T(""))
	, Score(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, TotalList);
	DDX_Text(pDX, IDC_EDIT1, Number);
	DDX_Text(pDX, IDC_EDIT2, Name);
	DDX_Text(pDX, IDC_EDIT3, Score);
	DDX_Control(pDX, IDC_BUTTON1, In);
	DDX_Control(pDX, IDC_BUTTON2, Out);
	DDX_Control(pDX, IDC_BUTTON3, Add);
	DDX_Control(pDX, IDC_BUTTON4, Delete);
	DDX_Control(pDX, IDC_BUTTON5, Exit);
}

BEGIN_MESSAGE_MAP(CScoreDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CScoreDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CScoreDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &CScoreDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CScoreDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CScoreDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CScoreDlg::OnBnClickedButton4)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CScoreDlg::OnNMClickList2)
END_MESSAGE_MAP()


// CScoreDlg ��Ϣ�������

BOOL CScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	AllocConsole();
	DWORD dwStyle = TotalList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl��
	TotalList.SetExtendedStyle(dwStyle); //������չ���
	TotalList.DeleteAllItems();//���
	TotalList.InsertColumn(0,_T("���"),LVCFMT_LEFT,150,0);//�����
	TotalList.InsertColumn(1,_T("ѧ��"),LVCFMT_LEFT,150,1);
	TotalList.InsertColumn(2,_T("����"),LVCFMT_LEFT,150,2);
	TotalList.InsertColumn(3,_T("�ɼ�"),LVCFMT_LEFT,150,3);
	//TotalList.InsertItem(0,_T("Item 1_1"));//������
	//TotalList.SetItemText(0,1,_T("item"));
	TotalList.SetRedraw(TRUE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CScoreDlg::OnPaint()
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
HCURSOR CScoreDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CScoreDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog file(true,NULL,NULL,OFN_OVERWRITEPROMPT|OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("Worksheet Files(*.xls,*.xlsx)|*.xls,*.xlsx|TXT Files(*.txt)|*.txt|All Files(*.*)|*.*||"),this);
	file.m_ofn.lpstrTitle = _T("��ѡ������ļ�");
	file.m_ofn.nMaxFile = 100;
	file.m_ofn.lpstrFile = new TCHAR[file.m_ofn.nMaxFile];
	ZeroMemory(file.m_ofn.lpstrFile,sizeof(TCHAR)*file.m_ofn.nMaxFile);
	int readFile = file.DoModal();
	if (readFile == IDCANCEL)
		return;
	POSITION filePosition;
	filePosition = file.GetStartPosition();
	CArray<CString,CString>fileName;
	while (filePosition != NULL)
		fileName.Add(file.GetNextPathName(filePosition));
	for (int i = 0; i < fileName.GetSize(); i++)
	{
		CString str;
		str = fileName.GetAt(i).Right(3);
		if ((str == "XLS")||(str == "XLSX")||(str == "xls")||(str == "xlsx"))
		{
			//readAndShowExcelFile(fileName.GetAt(i));
		}
		else if ((str == "TXT")||(str == "txt"))
		{
			readAndShowTxtFile(fileName.GetAt(i));
		}
	}
}


void CScoreDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CScoreDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

void CScoreDlg::readAndShowTxtFile(CString fileName)
{
	CStdioFile myFile;
	CString str;
	CString LineNumber;
	CString data[3];
	int i;
	int n;
	int linenumber;
	CRect rect;
	if(myFile.Open(fileName, CFile::modeRead))
	{
		while(myFile.ReadString(str))
		{
			n = str.GetLength();
			linenumber = TotalList.GetItemCount();
			for (i = 0; i < 2; i++)
			{
				int mark = str.Find(' ');
				data[i] = str.Mid(0,mark);
				str = str.Mid(mark + 1,n - mark - 1);
			}
			data[2] = str;
			if (!judge(data[0])) continue;
			LineNumber.Format(_T("%d"),linenumber + 1);
			TotalList.InsertItem(linenumber,LineNumber);
			for (i = 0; i < 3; i++)
			{
				TotalList.SetItemText(linenumber,i + 1,data[i]);
			}
		}
		myFile.Close();
	}
}

void CScoreDlg::OnBnClickedButton2()
{
	CFileDialog file(false,NULL,NULL,OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_READONLY,_T("Worksheet Files(*.xls,*.xlsx)|*.xls,*.xlsx|TXT Files(*.txt)|*.txt|All Files(*.*)|*.*||"),this);
	file.DoModal();
	CString fileName;
	fileName = file.GetPathName();
	CString str;
	str = fileName.Right(3);
	if ((str == "XLS")||(str == "XLSX")||(str == "xls")||(str == "xlsx"))
	{
		writeExcelFile(fileName);
	}
	else if ((str == "TXT")||(str == "txt"))
	{
		writeTxtFile(fileName);
	}
}


void CScoreDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyDialog Dlg;
	int linenumber = 0;
	CString LineNumber;
	Dlg.DoModal();
	linenumber = TotalList.GetItemCount();
	LineNumber.Format(_T("%d"),linenumber + 1);
	if (judge(Dlg.AddNumber))
	{
		TotalList.InsertItem(linenumber,LineNumber);
		TotalList.SetItemText(linenumber,1,Dlg.AddNumber);
		TotalList.SetItemText(linenumber,2,Dlg.AddName);
		TotalList.SetItemText(linenumber,3,Dlg.AddScore);
	}
	else
	{
		AfxMessageBox("��ѧ���Ѵ���!");
		return;
	}
}


void CScoreDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int itemPosition[100];
	int all = -1;
	POSITION pos = TotalList.GetFirstSelectedItemPosition();
	if (pos == NULL)
		return;
	else
	{
		while (pos)
		{
			all++;
			int nItem = TotalList.GetNextSelectedItem(pos);
			itemPosition[all] = nItem;
		}
	}
	for (int i = all; i >= 0; i--)
	{
		TotalList.DeleteItem(itemPosition[i]);
	}

	//�������±���
	int count;
	int i;
	CString count1;
	count = TotalList.GetItemCount();
	for (i = 0; i < count; i++)
	{
		count1.Format(_T("%d"),i+1);
		TotalList.SetItemText(i,0,count1);
	}
}


void CScoreDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = TotalList.GetFirstSelectedItemPosition();
	if (pos == NULL)
		return;
	else
	{
		int nItem = TotalList.GetNextSelectedItem(pos);
		Number = TotalList.GetItemText(nItem,1);
		Name = TotalList.GetItemText(nItem,2);
		Score = TotalList.GetItemText(nItem,3);
	}
	UpdateData(FALSE);
	*pResult = 0;
}

void CScoreDlg::writeTxtFile(CString FileName)
{
	//��������
	CStdioFile myWriteFile;
	CString str;
	int linenumber;
	myWriteFile.Open(FileName,CFile::modeCreate|CFile::modeWrite);
	UpdateData(TRUE);
	int i;
	linenumber = TotalList.GetItemCount();
	_cprintf("%d",linenumber);
	for (i = 0; i < linenumber; i++)
	{
		//str = TotalList.GetItemText(i,0);
		//str += ' ';
		str = "";
		str +=TotalList.GetItemText(i,1);
		str += ' ';
		str +=TotalList.GetItemText(i,2);
		str += ' ';
		str +=TotalList.GetItemText(i,3);
		str += ' ';
		str += "\n";
		myWriteFile.WriteString(str);
	}
	MessageBox(_T("�����ɹ���"),_T("��ʾ��Ϣ"),MB_OK);
}

/*void CScoreDlg::readAndShowExcelFile(CString FileName)
{
	//ShellExecute(NULL,NULL,FileName,NULL,NULL,SW_RESTORE);
	CDatabase db;
	CString sDriver = _T("MICROSOFT EXCEL DRIVER(*.XLS)");
	CString sSql,arr[3];
	//CString ExcelDriver = GetExcelDriver();
	sSql.Format(_T("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, FileName, FileName));
	if (!db.OpenEx(sSql,CDatabase::noOdbcDialog))
	{
		MessageBox(_T("��Excel�ļ�ʧ�ܣ�"),_T("����"),MB_OK);
		return;
	}
	//CRecordset pset(&db);
	//AfxMessageBox(_T("OK"));
	//sSql.Format(_T("SELECT ѧ��,����,�ɼ� FROM 1"));
	//pset.Open(CRecordset::forwardOnly,sSql,CRecordset::readOnly);
	//while(!pset.IsEOF())
	//{
		//pset.GetFieldValue(_T("ѧ��"),arr[0]);//ǰ���ֶα�������е���ͬ���������
		//pset.GetFieldValue(_T("����"),arr[1]);
		//pset.GetFieldValue(_T("�ɼ�"),arr[2]);
		
	//	int count = TotalList.GetItemCount();//���뵽ListCtrl��
	//	TotalList.InsertItem(count,arr[0]);
		//TotalList.SetItemText(count,1,arr[1]);
	//	TotalList.SetItemText(count,2,arr[2]);
	//	pset.MoveNext();
	//}
 db.Close();
 MessageBox(_T("Excel���ݳɹ�����ϵͳ!"),_T("����ɹ�"));
}*/

CString CScoreDlg::GetExcelDriver()
{
	char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
    // ��ȡ�Ѱ�װ����������(������odbcinst.h��)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return ("");
   
    // �����Ѱ�װ�������Ƿ���Excel...
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            //���� !
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
    return sDriver;
}

void CScoreDlg::writeExcelFile(CString FileName)
{
	if ( TotalList.GetItemCount() <= 0 )
	{
		AfxMessageBox("�б���û�м�¼��Ҫ���棡");
		return;
	}
	
	DWORD dwRe = GetFileAttributes(FileName);
	if ( dwRe != (DWORD)-1 )
	{
		DeleteFile(FileName);
	}
	
	CDatabase database;
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; 
	CString sSql,strInsert;
	
	TRY
	{
		// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, FileName, FileName);

       // �������ݿ� (��Excel����ļ�)
		if( database.OpenEx(sSql,CDatabase::noOdbcDialog))
		{
			//����б��������
			int iColumnNum,iRowCount;
			LVCOLUMN lvCol;
			CString strColName; //���ڱ����б�������
			int i,j; //�С���ѭ������
			
			iColumnNum = TotalList.GetHeaderCtrl()->GetItemCount();
			iRowCount = TotalList.GetItemCount();

			sSql = " CREATE TABLE DSO_DX ( ";
			strInsert = " INSERT INTO DSO_DX ( " ;
			//����б�������
			lvCol.mask = LVCF_TEXT; //�������ã�˵��LVCOLUMN������pszText������Ч
			lvCol.cchTextMax = 32; //���裬pszText������ָ����ַ����Ĵ�С
			lvCol.pszText = strColName.GetBuffer(32); //���裬pszText ��ָ����ַ�����ʵ�ʴ洢λ�á�
			//���������������ú����ͨ�� GetColumn()��������б��������
			for( i=0 ; i< iColumnNum ; i++ )
			{
				if ( !(TotalList.GetColumn(i,&lvCol)))
					return;
				if ( i<iColumnNum-1 )
				{
					sSql = sSql + lvCol.pszText + " TEXT , ";
					strInsert = strInsert + lvCol.pszText + " , ";
				}
				else
				{
					sSql = sSql + lvCol.pszText + " TEXT ) ";
					strInsert = strInsert + lvCol.pszText + " )  VALUES ( ";
				}
			}
			//����Excel����ļ�
			database.ExecuteSQL(sSql);
			
			//ѭ����ȡ��¼�����뵽EXCEL��
			sSql = strInsert;
			char chTemp[33];
			for ( j=0 ; j<iRowCount ; j++ )
			{
				memset(chTemp,0,33);
				for ( i=0 ; i<iColumnNum ; i++ )
				{
					TotalList.GetItemText(j,i,chTemp,33);
					if ( i < (iColumnNum-1) )
					{
						sSql = sSql + "'" + chTemp + "' , ";
					}
					else
					{
						sSql = sSql + "'" + chTemp + "' ) ";
					}
				}
				//����¼���뵽�����
				database.ExecuteSQL(sSql);
				sSql = strInsert; 
			}
		}     
	
		// �ر�Excel����ļ�
		database.Close();
		
		AfxMessageBox("�����ѯ���ΪExcel�ļ��ɹ���");
	}
	CATCH_ALL(e)
	{
		//�������ͺܶ࣬������Ҫ���б���
		AfxMessageBox("Excel�ļ�����ʧ�ܡ�");
	}
	END_CATCH_ALL;
}

bool CScoreDlg::judge(CString studentNumber)
{
	CString number;
	int n;
	int i;
	n = TotalList.GetItemCount();
	for (i = 0; i < n; i++)
	{
		number = TotalList.GetItemText(i,1);
		if (studentNumber == number)
			return false;
	}
	return true;
}