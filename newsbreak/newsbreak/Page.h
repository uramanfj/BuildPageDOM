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

	//��һ����ҳ�������е����ݱ�����buffer��
	int getpage()
	{
		HINTERNET hInternet =
			InternetOpen(UserAgent, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);//��ʼ��WinINet	

		HINTERNET hConnect =
			InternetConnectA(hInternet, urlStr, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);//���ӷ�����	

		HINTERNET hOpenRequest =
			HttpOpenRequest(hConnect, "GET", "/index.html", NULL, NULL, (LPCSTR*)"*/*", INTERNET_FLAG_DONT_CACHE, 1);//����http����	

		BOOL bRequest = HttpSendRequestA(hOpenRequest, NULL, 0, NULL, 0);//����http����
		
		char szBuffer[1024] = { 0 };	
		DWORD dwByteRead = 0;	

		//����ҳ������string buffer�
		while (InternetReadFile(hOpenRequest, szBuffer, sizeof(szBuffer), &dwByteRead) && dwByteRead > 0)
		{
			buffer += szBuffer;
			ZeroMemory(szBuffer, dwByteRead);
		}
		/** ������ҳ��1.html�ļ�
		FILE* fp = NULL;

		fopen_s(&fp, filename.c_str(), "wb");
		while (InternetReadFile(hOpenRequest, szBuffer, sizeof(szBuffer), &dwByteRead) && dwByteRead > 0) 
		{ 
			fwrite(szBuffer, dwByteRead, 1, fp);		
			ZeroMemory(szBuffer, dwByteRead); 
		}	
		fclose(fp);
		*/

		//�ر�http����
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