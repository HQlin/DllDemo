
// DllTestDlg.h : ͷ�ļ�
//

#pragma once
#include "StaticDll.h"
#pragma comment(lib, "StaticDll.lib") 

// CDllTestDlg �Ի���
class CDllTestDlg : public CDialogEx
{
// ����
public:
	CDllTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DLLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CStaticDll * m_dll;

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
	afx_msg void OnBnClickedBtnSta();
	afx_msg void OnBnClickedBtnDyn();
};
