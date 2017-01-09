
// TEST_QR.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CTEST_QRApp: 
// 有关此类的实现，请参阅 TEST_QR.cpp
//

class CTEST_QRApp : public CWinApp
{
public:
	CTEST_QRApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CTEST_QRApp theApp;