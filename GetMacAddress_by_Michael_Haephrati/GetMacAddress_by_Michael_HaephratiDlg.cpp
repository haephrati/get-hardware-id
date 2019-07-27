
// GetMacAddress_by_Michael_HaephratiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetMacAddress_by_Michael_Haephrati.h"
#include "GetMacAddress_by_Michael_HaephratiDlg.h"
#include "afxdialogex.h"
#include "Iphlpapi.h"
#include "HardDriveSerialNumer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CGetMacAddress_by_Michael_HaephratiDlg dialog




CGetMacAddress_by_Michael_HaephratiDlg::CGetMacAddress_by_Michael_HaephratiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetMacAddress_by_Michael_HaephratiDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetMacAddress_by_Michael_HaephratiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGetMacAddress_by_Michael_HaephratiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGetMacAddress_by_Michael_HaephratiDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGetMacAddress_by_Michael_HaephratiDlg message handlers

BOOL CGetMacAddress_by_Michael_HaephratiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Here we show the MAC Address
	ShowMACAddress();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetMacAddress_by_Michael_HaephratiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGetMacAddress_by_Michael_HaephratiDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGetMacAddress_by_Michael_HaephratiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGetMacAddress_by_Michael_HaephratiDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

wchar_t *GetWText(std::vector<char> &v){
	int w_num = v.size() + 1;
	wchar_t* w_str = new wchar_t[w_num];	w_str[w_num - 1] = 0;
	MultiByteToWideChar(CP_UTF8, 0, (char *) &v[0], v.size(), w_str, w_num);
	return w_str;
}

void CGetMacAddress_by_Michael_HaephratiDlg::ShowMACAddress()
{
	// Get the buffer length required for IP_ADAPTER_INFO.
	ULONG BufferLength = 0;
	BYTE* pBuffer = 0;
	if( ERROR_BUFFER_OVERFLOW == GetAdaptersInfo( 0, &BufferLength ))
	{
		// Now the BufferLength contain the required buffer length.
		// Allocate necessary buffer.
		pBuffer = new BYTE[ BufferLength ];
	}
	else
	{
		// Error occurred. handle it accordingly.
	}

	// Get the Adapter Information.
	PIP_ADAPTER_INFO pAdapterInfo =
		  reinterpret_cast<PIP_ADAPTER_INFO>(pBuffer);
	GetAdaptersInfo( pAdapterInfo, &BufferLength );

	// Iterate the network adapters and print their MAC address.
	while( pAdapterInfo )
	{
		// Assuming pAdapterInfo->AddressLength is 6.
		CString csMacAddress;
		csMacAddress.Format(_T("%02x:%02x:%02x:%02x:%02x:%02x"),
							pAdapterInfo->Address[0],
							pAdapterInfo->Address[1],
							pAdapterInfo->Address[2],
							pAdapterInfo->Address[3],
							pAdapterInfo->Address[4],
							pAdapterInfo->Address[5]);

		MessageBox(csMacAddress,_T("Your first MAC Address is"));

		// Get Hard Drive Serial Number
		std::vector<char> hwId;
		MasterHardDiskSerial diskSerial;
        diskSerial.GetSerialNo(hwId);
        if (hwId.empty())
        {
            throw std::runtime_error("Can't retrieve hardware serial number");
        }

		wchar_t *w_hwId = GetWText(hwId);
		CString cs = CString(&hwId[0], hwId.size());
		MessageBox(cs, _T("HardDrive Serial Number"));
		delete w_hwId;
		
		break;
		// Get next adapter info.
		pAdapterInfo = pAdapterInfo->Next;
	}
	CDialogEx::OnOK();
	// deallocate the buffer.
	delete[] pBuffer;
}


