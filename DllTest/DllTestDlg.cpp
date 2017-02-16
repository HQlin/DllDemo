
// DllTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DllTest.h"
#include "DllTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDllTestDlg �Ի���




CDllTestDlg::CDllTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDllTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDllTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDllTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STA, &CDllTestDlg::OnBnClickedBtnSta)
	ON_BN_CLICKED(IDC_BTN_DYN, &CDllTestDlg::OnBnClickedBtnDyn)
END_MESSAGE_MAP()


// CDllTestDlg ��Ϣ�������

BOOL CDllTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDllTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDllTestDlg::OnPaint()
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
HCURSOR CDllTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDllTestDlg::OnBnClickedBtnSta()
{
	//---��̬����---
	//�����ļ���
	//#include "StaticDll.h"
	//#pragma comment(lib, "StaticDll.lib") 
	//�ɵ��÷�ʽ��
	//�ࣨͷ�ļ�������->CStaticDll
	//ȫ�ֱ���->nStaticDll
	//ȫ�ֺ���->fnStaticDll()
	CString str;
	str.Format(L" CODE:m_dll->GetInt(1), RETURN:%d \n CODE:nDll, RETURN:%d \n CODE:fnDll(), RETURN:%d \n", 
		m_dll->GetInt(1), nStaticDll, fnStaticDll());
	MessageBox(str);
}


void CDllTestDlg::OnBnClickedBtnDyn()
{
	//---��̬̬����---
	//����Ҫ�ⲿ�����Զ����࣬���������ͷ�ļ���
	//��������Ҫ�ⲿ�����Զ�����
	//�ɵ��÷�ʽ��
	//ȫ�ֺ���->GetInt
	CString dllName = L"DynamicDll.dll";
	HINSTANCE hDll = LoadLibrary(dllName);
	if (NULL == hDll)
	{
		MessageBox(L"���� %s ʧ��",dllName);
	}
	typedef int (*pfGetInst)();
	pfGetInst pfnDll = (pfGetInst)GetProcAddress(hDll,"GetInt");
	if (NULL==pfnDll)
	{
		MessageBox(L"DLL�к���Ѱ��ʧ��");
	}

	CString str;
	str.Format(L" CODE:pfnDll(), RETURN:%d \n", 
		pfnDll());
	MessageBox(str);
}
