#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <windows.h>
#include <Wininet.h>
#include <gumbo.h>
#include "Page.h"
#include "domBuilder.h"

#ifndef __FIND_H__
#define __FIND_H__

using namespace std;


int main()
{
	Page p("www.baidu.com");

	domBuilder db(p.getbuf());
}

#endif	//__FIND_H__
//end of file