#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <gumbo.h>

#ifndef __DOMBUILDER_H__
#define __DOMBUILDER_H__

using namespace std;

typedef struct qualificationsNode
{
	long long textLen;
	long long imgArea;
	long long otherTextLen;
	long long otherImgArea;
	long long otherCount;

	qualificationsNode()
	{
		textLen = 0;
		imgArea = 0;
		otherTextLen = 0;
		otherImgArea = 0;
		otherCount = 0;
	}

}Quas;

class domBuilder
{
private:
	GumboNode *domroot;
	string &file;
	Quas qualification;

	inline long long textNode(GumboNode* node)
	{

	}

	inline long long imgNode(GumboNode* node)
	{
	}

	inline long long otherNode(GumboNode* node)
	{

	}

	inline long long visitFunc(GumboNode* node)
	{

	}

	inline void DFS(GumboNode* root)
	{
		if (root->type == GUMBO_NODE_ELEMENT || root->type == GUMBO_NODE_DOCUMENT)
		{
			GumboVector child = root->v.element.children;

			for (int i = 0; i < child.length; i++)
			{
				DFS((GumboNode*)child.data[i]);
			}
		}

		switch (root->type)
		{
			case GUMBO_NODE_TEXT:
			case GUMBO_NODE_CDATA:

		}

	}

public:
	void buildDom()
	{
		GumboOutput *output = gumbo_parse(file.c_str());
		domroot = output->root;
	}

	Quas& getQuas() { return qualification; }
	GumboNode *getroot() { return domroot; }

	domBuilder(string& filedata) :file(filedata) 
	{
		buildDom();
	}

	~domBuilder() {}
};

#endif //__DOMBUILDER_H__
//End of File