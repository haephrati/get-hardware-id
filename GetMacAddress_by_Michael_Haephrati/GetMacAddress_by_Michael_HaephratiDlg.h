
// GetMacAddress_by_Michael_HaephratiDlg.h : header file
//

#pragma once


// CGetMacAddress_by_Michael_HaephratiDlg dialog
class CGetMacAddress_by_Michael_HaephratiDlg : public CDialogEx
{
// Construction
public:
	CGetMacAddress_by_Michael_HaephratiDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GETMACADDRESS_BY_MICHAEL_HAEPHRATI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void ShowMACAddress();
};
