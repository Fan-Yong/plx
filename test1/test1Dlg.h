
// test1Dlg.h: 头文件
//

#pragma once
#include "PlxApi.h"

// Ctest1Dlg 对话框
class Ctest1Dlg : public CDialogEx
{
// 构造
public:
	Ctest1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	PLX_DEVICE_KEY PD_9056;
	PLX_DEVICE_OBJECT Device;
	CEdit DL;
	//CButton iii;
	CEdit iii;
	afx_msg void OnBnClickedButton3();	
	afx_msg void OnBnClickedButton4();
};
