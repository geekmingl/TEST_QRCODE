
// TEST_QRDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TEST_QR.h"
#include "TEST_QRDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/* add by mingl */
using namespace std;

#include "QrCode.hpp"
using namespace qrcodegen;

#include "svgpp/svgpp.hpp"
using namespace svgpp;

/* end by mingl */


// CTEST_QRDlg �Ի���



CTEST_QRDlg::CTEST_QRDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_QR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTEST_QRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTEST_QRDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CTEST_QRDlg::OnBnClickedButtonTest)
END_MESSAGE_MAP()


// CTEST_QRDlg ��Ϣ�������

BOOL CTEST_QRDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTEST_QRDlg::OnPaint()
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
HCURSOR CTEST_QRDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTEST_QRDlg::OnBnClickedButtonTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// Simple operation
	QrCode qr0 = QrCode::encodeText("Hello, world!", QrCode::Ecc::MEDIUM);
	std::string svg = qr0.toSvgString(4);

	// Manual operation
	std::vector<QrSegment> segs =
		QrSegment::makeSegments("3141592653589793238462643383");
	QrCode qr1 = QrCode::encodeSegments(segs, QrCode::Ecc::HIGH, 5, 5, 2, false);


}
