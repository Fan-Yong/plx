
// test1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "test1.h"
#include "test1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest1Dlg 对话框



Ctest1Dlg::Ctest1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, DL);
	//DDX_Control(pDX, IDC_BUTTON1, iii);
	DDX_Control(pDX, IDC_EDIT3, iii);
}

BEGIN_MESSAGE_MAP(Ctest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Ctest1Dlg 消息处理程序

BOOL Ctest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	iii.SetWindowTextW(_T(""));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest1Dlg::OnBnClickedButton1()
{
	U8 VerMajor;
	U8 VerMinor;
	U8 VerRev;
	PlxPci_ApiVersion(
		&VerMajor,
		&VerMinor,
		&VerRev
	);
	CString str;  

	int i = 100;
	str.Format(_T("%d.%d.%d"), VerMajor, VerMinor, VerRev);
	MessageBox(str);
	
	
	// TODO: 在此添加控件通知处理程序代码
}


void Ctest1Dlg::OnBnClickedButton2()
{
	PLX_STATUS rc;
	PLX_DEVICE_KEY DeviceKey;
	// Clear key structure to find first device
	CString str;
	CString s;
	CString s1;
	
	s = "";
	memset(&DeviceKey, PCI_FIELD_IGNORE, sizeof(PLX_DEVICE_KEY));
	rc =
		PlxPci_DeviceFind(
			&DeviceKey,
			0 // Select 1st device matching criteria
		);
	/*if (rc != PLX_STATUS_OK)
	{
		// ERROR – Unable to locate matching device
		MessageBox(TEXT("Unable to locate matching device"));
	}
	}*/
	int i = 0;

	while (rc == PLX_STATUS_OK) {
		
		
		str.Format(_T("%x-%x,"), DeviceKey.DeviceId, DeviceKey.VendorId);
		s.Append(str);
		iii.SetWindowTextW(s);
		s1.Format(_T("%x"), DeviceKey.DeviceId);

		if (s1=="9056") {

			PD_9056 = DeviceKey;
			MessageBox(s1);
		}

		
		
		memset(&DeviceKey, PCI_FIELD_IGNORE, sizeof(PLX_DEVICE_KEY));
		i++;
		rc =
			PlxPci_DeviceFind(
				&DeviceKey,
				i // Select 1st device matching criteria
			);

	}



	
}


void Ctest1Dlg::OnBnClickedButton3()
{
	CString str;	
	PLX_STATUS rc;
	
	

	rc =
		PlxPci_DeviceOpen(
			&PD_9056,
			&Device
		);
	if (rc != ApiSuccess)
	{
		MessageBox(_T("未找到设备"));
		return;
		
	}
	
	str.Format(_T("%x"), Device.Key.DeviceId);
	MessageBox(str);

	rc = PlxPci_DmaChannelOpen(
		&Device,
		0, // Channel 0
		NULL // Do not modify current DMA properties
	);
	if (rc != PLX_STATUS_OK){
		str.Format(_T("%d"), rc);
		//MessageBox(str);
		MessageBox(_T("建立通道失败"));
		return;
	}
	MessageBox(_T("建立通道成功"));

	

	
}


void Ctest1Dlg::OnBnClickedButton4()
{
	
	/*CString str;
	PLX_STATUS rc;
	U8  pBuffer;
	PLX_DMA_PARAMS DmaParams;
	
	

	
	// Allocate a 500k buffer
	pBuffer =U8(malloc(500 * 1024));
	// Clear DMA parameters
	memset(&DmaParams, 0, sizeof(PLX_DMA_PARAMS));
	// Setup DMA parameters (9000 DMA)
	DmaParams.UserVa = pBuffer;
	DmaParams.ByteCount = (500 * 1024);

	 

	 
		
	// 9000/8311 DMA
	DmaParams.LocalAddr = 0x0;
	DmaParams.Direction = PLX_DMA_LOC_TO_PCI;
	 
	rc =PlxPci_DmaTransferUserBuffer(
			&Device,
			0, // Channel 0
			&DmaParams, // DMA transfer parameters
			(3 * 1000) // Specify time to wait for DMA completion
		);

	str.Format(_T("%d"), rc);
	MessageBox(str);
	if (rc != ApiSuccess)
	{
		if (rc == ApiWaitTimeout){
			MessageBox(_T("Timed out waiting for DMA completion"));
		}
		else {
			MessageBox(_T(" ERROR - Unable to perform DMA transfer"));
		}
	}
	MessageBox(_T(" OK"));*/
	CString str;
	PLX_STATUS rc;
	PLX_DMA_PARAMS DmaParams;
	PLX_PHYSICAL_MEM PciBuffer;
	// Get Common buffer information
	PlxPci_CommonBufferProperties(
		&Device,
		&PciBuffer
	);
	memset(&DmaParams, 0, sizeof(PLX_DMA_PARAMS));
	// Fill in DMA transfer parameters
	DmaParams.ByteCount = 0x1000;
	
	// 9000/8311 DMA
	DmaParams.PciAddr = PciBuffer.PhysicalAddr;
	DmaParams.LocalAddr = 0x0;
	DmaParams.Direction = PLX_DMA_LOC_TO_PCI;
	
	rc =
		PlxPci_DmaTransferBlock(
			&Device,
			0, // Channel 0
			&DmaParams, // DMA transfer parameters
			(3 * 1000) // Specify time to wait for DMA completion
		);
	if (rc != PLX_STATUS_OK)
	{
		if (rc == ApiWaitTimeout) {
			MessageBox(_T("Timed out waiting for DMA completion"));
		}
		else {
			MessageBox(_T(" ERROR - Unable to perform DMA transfer"));
		}
	}
	str.Format(_T("%d"), rc);
	MessageBox(str);

}
