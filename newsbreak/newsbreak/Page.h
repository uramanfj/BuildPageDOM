#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>
#include <Wininet.h>

#pragma comment(lib, "WinInet.lib")

#ifndef __PAGE_H__
#define __PAGE_H__

#define UserAgent "Mozilla / 5.0 (Windows NT 10.0; Win64; x64) AppleWebKit / 537.36 (KHTML, like Gecko) Chrome / 64.0.3282.140 Safari / 537.36 Edge / 18.17763"

using namespace std;

class Page
{
private:
	char* urlStr;
	string buffer;

	//打开一个网页，将其中的内容保存在buffer里
	int getpage()
	{
		HINTERNET hInternet =
			InternetOpen(UserAgent, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);//初始化WinINet	

		HINTERNET hConnect =
			InternetConnectA(hInternet, urlStr, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);//连接服务器	

		HINTERNET hOpenRequest =
			HttpOpenRequest(hConnect, "GET", "/index.html", NULL, NULL, (LPCSTR*)"*/*", INTERNET_FLAG_DONT_CACHE, 1);//创建http请求	

		BOOL bRequest = HttpSendRequestA(hOpenRequest, NULL, 0, NULL, 0);//发送http请求
		
		char szBuffer[1024] = { 0 };	
		DWORD dwByteRead = 0;	

		//将网页保存在string buffer里；
		while (InternetReadFile(hOpenRequest, szBuffer, sizeof(szBuffer), &dwByteRead) && dwByteRead > 0)
		{
			buffer += szBuffer;
			ZeroMemory(szBuffer, dwByteRead);
		}
		/** 下载网页至1.html文件
		FILE* fp = NULL;

		fopen_s(&fp, filename.c_str(), "wb");
		while (InternetReadFile(hOpenRequest, szBuffer, sizeof(szBuffer), &dwByteRead) && dwByteRead > 0) 
		{ 
			fwrite(szBuffer, dwByteRead, 1, fp);		
			ZeroMemory(szBuffer, dwByteRead); 
		}	
		fclose(fp);
		*/

		//关闭http链接
		InternetCloseHandle(hOpenRequest);
		InternetCloseHandle(hConnect);
		InternetCloseHandle(hInternet);

		return 0;
	}

public:
	string& getbuf() { return buffer; }

	Page(char *url = nullptr) :urlStr(url) 
	{
		getpage();
	}

	~Page() {}
};

#endif //__PAGE_H__
//End of File