
// TEST_QR.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTEST_QRApp: 
// �йش����ʵ�֣������ TEST_QR.cpp
//

class CTEST_QRApp : public CWinApp
{
public:
	CTEST_QRApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTEST_QRApp theApp;