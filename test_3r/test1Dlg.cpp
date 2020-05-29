
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
	//DDX_Control(pDX, IDC_EDIT3, iii);
	DDX_Control(pDX, IDC_EDIT1, bbb);
	DDX_Control(pDX, IDC_RADIO1, r1);
	DDX_Control(pDX, IDC_RADIO2, r2);
	DDX_Control(pDX, IDC_EDIT2, ELocalAddress);
	DDX_Control(pDX, IDC_EDIT3, EByte);
}

BEGIN_MESSAGE_MAP(Ctest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ctest1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ctest1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &Ctest1Dlg::OnBnClickedButton6)
	//ON_BN_CLICKED(IDC_BUTTON5, &Ctest1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &Ctest1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &Ctest1Dlg::OnBnClickedButton5)
	//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Ctest1Dlg::OnTcnSelchangeTab1)
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
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE); //选上
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//
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

U32 Ctest1Dlg::swap_endian(U32 val) {
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
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
	CString str;	
	CString s1;
	
	
	memset(&PD_9056, PCI_FIELD_IGNORE, sizeof(PLX_DEVICE_KEY));
	rc =
		PlxPci_DeviceFind(
			&PD_9056,
			0 // Select 1st device matching criteria
		);
	if (rc != PLX_STATUS_OK)
	{
		// ERROR – Unable to locate matching device
		MessageBox(TEXT("Unable to locate matching device"));
		return;
	}
	
	int i = 0;
	while (rc == PLX_STATUS_OK) {		
		s1.Format(_T("%x"), PD_9056.DeviceId);

		if (s1=="9056") {			
			MessageBox(_T("找到9056设备!"));			
			return ;
		}		
		memset(&PD_9056, PCI_FIELD_IGNORE, sizeof(PLX_DEVICE_KEY));
		i++;
		rc =
			PlxPci_DeviceFind(
				&PD_9056,
				i // Select 1st device matching criteria
			);
	}
	MessageBox(_T("没有找到9056设备!"));
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
		MessageBox(_T("设备不能正常打开"));
		return;
		
	}
	
	//str.Format(_T("%x"), Device.Key.DeviceId);
	//MessageBox(str);

	rc = PlxPci_DmaChannelOpen(
		&Device,
		1, // Channel 0
		NULL // Do not modify current DMA properties
	);
	if (rc != PLX_STATUS_OK){
		str.Format(_T("建立通道失败%d"), rc);
		//MessageBox(str);
		MessageBox(str);
		return;
	}
	MessageBox(_T("建立通道成功"));
	 
}


void Ctest1Dlg::OnBnClickedButton4()
{
	
	
	CString str;
	PLX_STATUS rc;
	PLX_DMA_PARAMS DmaParams;
	PLX_PHYSICAL_MEM PciBuffer;
	PLX_NOTIFY_OBJECT NotifyObject;
	PLX_INTERRUPT     PlxInterrupt;

	/*
	// Clear interrupt fields
	memset(&PlxInterrupt, 0, sizeof(PLX_INTERRUPT));
	// Setup to wait for selected DMA channel
	PlxInterrupt.DmaDone = 1;
	rc =
		PlxPci_NotificationRegisterFor(
			&Device,
			&PlxInterrupt,
			&NotifyObject
		);

	if (rc != PLX_STATUS_OK)
	{
		MessageBox(_T("注册中断事件失败"));
		return;
	}
	*/

	void* pBuffer;
	// Get Common buffer information
	PlxPci_CommonBufferProperties(
		&Device,
		&PciBuffer
	);

	rc =
		PlxPci_CommonBufferMap(
			&Device,
			&pBuffer
		);
	if (rc != PLX_STATUS_OK)
	{
		MessageBox(_T("  Unable to map common buffer to user virtual space"));
		return;
	}
	memset(&DmaParams, 0, sizeof(PLX_DMA_PARAMS));

	
	/*//获取对话框数据
	CString s;
	bbb.GetWindowTextW(s);
	U32 nValude;
	const char* sc = CStringA(s);
	sscanf_s(sc, "%x", &nValude);
U32 nValude;
	*(U32*)pBuffer = nValude;

	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()) {
		DmaParams.ByteCount = 0x0004;
	}
	else {
		DmaParams.ByteCount = 0x0008;
		*((U32*)pBuffer+1) = nValude;

	} */
	//const char src[160] = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789";
	U32 src[40];
	for (int i = 0; i < 40; i++) {
		src[i] = swap_endian(0x12345678);
		 
	}	
	memcpy(pBuffer, src, 160);  
	
	 

	DmaParams.ByteCount = 0x00A4;
	// 9000/8311 DMA
	DmaParams.PciAddr = PciBuffer.PhysicalAddr;
	DmaParams.LocalAddr = 0x040;
	DmaParams.Direction = PLX_DMA_PCI_TO_LOC;
	
	rc =
		PlxPci_DmaTransferBlock(
			&Device,
			1, // Channel 1
			&DmaParams, // DMA transfer parameters
			(1000) // Specify time to wait for DMA completion
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
	else {

		/*rc =
			PlxPci_NotificationWait(
				&Device,
				&NotifyObject,
				1 * 1000
			);
		switch (rc)
		{
		case PLX_STATUS_OK:
			MessageBox(_T(" DMA Int received "));
			break;

		case PLX_STATUS_TIMEOUT:
			MessageBox(_T("Timeout waiting for Int Event "));

			break;

		case PLX_STATUS_CANCELED:
			MessageBox(_T("*ERROR* - Interrupt event cancelled"));
			break;

		}*/
	}






	str.Format(_T("数据传输码:%d"), rc);
	MessageBox(str);




}


void Ctest1Dlg::OnBnClickedButton6()
{

	CString s;
	bbb.GetWindowTextW(s);
	U32 nValude;
	const char* sc = CStringA(s);
	sscanf_s(sc, "%x", &nValude);



	s.Format(_T("%x"), nValude);
	MessageBox(s);    //显示输入值对应的10进制 

}





void Ctest1Dlg::OnBnClickedButton7()

{
	CString str;
	PLX_STATUS rc;

	/*rc=PlxPci_DeviceReset(
		&Device
	);
	str.Format(_T("关闭设备码:%d"), rc);
	MessageBox(str);*/

	rc =
		PlxPci_DmaChannelClose(
			&Device,
			1 // Channel 1
		);
	if (rc != PLX_STATUS_OK)
	{
		// Reset the device if a DMA is in-progress
		if (rc == PLX_STATUS_IN_PROGRESS)
		{
			PlxPci_DeviceReset(
				&Device
			);
			// Attempt to close again
			PlxPci_DmaChannelClose(
				&Device,
				1
			);
		}
	}

	str.Format(_T("数据通道关闭码:%d"), rc);
	MessageBox(str);

}


void Ctest1Dlg::OnBnClickedButton5()
{

	U8                DmaChannel;
	void* pUserBuffer = NULL;
	U16               ChannelInput;
	U32               LocalAddress;
	PLX_STATUS        rc;
	PLX_DMA_PROP      DmaProp;
	PLX_INTERRUPT     PlxInterrupt;
	PLX_DMA_PARAMS    DmaParams;
	PLX_PHYSICAL_MEM  PciBuffer;
	PLX_NOTIFY_OBJECT NotifyObject;

	///////////////////////////////////////////////////
	int ninput = 1;
	U32 nbyte = 0x20;
	int n = 32;
	DmaChannel = 1;
	LocalAddress = 0x44;
	/////////////////////////////////////////////////

	CString s;
	ELocalAddress.GetWindowTextW(s);
	if(s == "") {
		MessageBox(_T("请填写LocalAddress"));
		return;

	}
	const char* sc = CStringA(s);
	sscanf_s(sc, "%x", &LocalAddress);

	EByte.GetWindowTextW(s);
	sc = CStringA(s);
	if (s == "") {
		MessageBox(_T("请填写十六进制读取位数"));
		return;

	}

	sscanf_s(sc, "%x", &nbyte);
	sscanf_s(sc, "%x", &n);


	rc =
		PlxPci_DeviceOpen(
			&PD_9056,
			&Device
		);
	if (rc != ApiSuccess)
	{
		MessageBox(_T("设备不能正常打开"));
		return;

	}
	
	
	//第一步 建立通道-------------------------------------------------------------------------
	
	// Clear DMA structure
	memset(&DmaProp, 0, sizeof(PLX_DMA_PROP));

	DmaProp.LocalBusWidth = 1;
	DmaProp.ReadyInput = ninput;

	DmaProp.Burst = 1;
	DmaProp.BurstInfinite = 1;
	DmaProp.DoneInterrupt = 1;
	DmaProp.RouteIntToPci = 1;

	rc =
		PlxPci_DmaChannelOpen(
			&Device,
			DmaChannel,
			&DmaProp
		);

	if (rc == PLX_STATUS_OK)
	{
		MessageBox(_T("建立通道成功"));
	}
	else
	{
		MessageBox(_T("建立通道失败"));	
		goto label2;
	}
	//第一步 建立通道完毕-------------------------------------------------------------------------
	
	
	
	
	//第二步骤 Register for notification------------------------------------------------------------
	// Setup to wait for selected DMA channel
	PlxInterrupt.DmaDone = (1 << DmaChannel);

	rc =
		PlxPci_NotificationRegisterFor(
			&Device,
			&PlxInterrupt,
			&NotifyObject
		);

	if (rc != PLX_STATUS_OK)
	{
		MessageBox(_T("Register for notification失败"));
		goto label1;
	}

	//第三步骤传输数据
	pUserBuffer = malloc(nbyte);
	// Clear DMA data
	memset(&DmaParams, 0, sizeof(PLX_DMA_PARAMS));

	DmaParams.UserVa = (PLX_UINT_PTR)pUserBuffer;
	DmaParams.LocalAddr = LocalAddress;
	DmaParams.ByteCount = nbyte;
	DmaParams.Direction = PLX_DMA_LOC_TO_PCI;

	rc =
		PlxPci_DmaTransferUserBuffer(
			&Device,
			DmaChannel,
			&DmaParams,
			0         // Specify a timeout to let API perform wait
		);
	if (rc != PLX_STATUS_OK) {

		MessageBox(_T("传输数据失败"));

	}
	else {
		rc =
			PlxPci_NotificationWait(
				&Device,
				&NotifyObject,
				5 * 1000
			);

		switch (rc)
		{
		case PLX_STATUS_OK:
			//MessageBox(_T("Ok (DMA Int received"));

			rc =
				PlxPci_NotificationStatus(
					&Device,
					&NotifyObject,
					&PlxInterrupt
				);

			if (rc != PLX_STATUS_OK)
			{

				MessageBox(_T("*ERROR* - NotificationStatus failed"));
			}
			else {


				U8 nvalue;
				CString s1;
				CString s2;
				s2 = "";
				for (int i = 0; i < 32; i++) {
					nvalue = *(U8*)((U8*)pUserBuffer + i);
					s1.Format(_T("%x"), nvalue);
					s2.Append(s1 + ",");


				}
				MessageBox(s2);
			}
			break;

		case PLX_STATUS_TIMEOUT:
			MessageBox(_T("*ERROR* - Timeout waiting for Int Event"));
			break;

		case PLX_STATUS_CANCELED:
			MessageBox(_T("*ERROR* - Interrupt event cancelled"));
			break;

		default:
			MessageBox(_T("*ERROR* - NotificationWait failed"));
			break;
		}
	}

	label1:
	//关闭通知
	rc =
		PlxPci_NotificationCancel(
			&Device,
			&NotifyObject
		);

	if (rc != PLX_STATUS_OK)
	{
		MessageBox(_T("*ERROR* - 关闭通知 API failed"));
		 
	}
	else
	{
		//s1.Format(_T(" 关闭通知 成功"));
	}
	
	// Close DMA Channel
label2:
	rc =
		PlxPci_DmaChannelClose(
			&Device,
			DmaChannel
		);

	if (rc == PLX_STATUS_OK)
	{
		//MessageBox(_T("关闭通道成功"));
	}
	else
	{
		MessageBox(_T("*ERROR* - 关闭通道 API failed"));
		 
	}
	 
	// Release user buffer
	if (pUserBuffer != NULL)
		free(pUserBuffer);

	
	CString s1;
	rc= PlxPci_DeviceClose(
		&Device
	);
	if (rc == PLX_STATUS_OK)
	{
		//MessageBox(_T("关闭设备成功"));
	}
	else {
		s1.Format(_T("关闭设备码:%d"), rc);
		MessageBox(s1);
	}
}





