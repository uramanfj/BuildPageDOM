#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <gumbo.h>

#ifndef __JUDGER_H__
#define __JUDGER_H__

using namespace std;

class judger
{
private:
	string filename;

public:
	judger(string &name) :filename(name) {}
	~judger();
};

#endif	//__JUDGER_H__
//end of file