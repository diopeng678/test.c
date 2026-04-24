#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include"Seqlist.h"

int main()
{
	SL s;
	SLInit(&s);
	SLPushback(&s, 1);
	SLPushback(&s, 2);
	SLPushback(&s, 4);
	SLPushfornt(&s, 0);
	SLPrint(s);
	

	return 0;
}