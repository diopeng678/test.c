#include"sequlist.h"

int main()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushFront(&sl,7 );
	SLPushFront(&sl, 8);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 67);



	SLPrint(&sl);



	SLDestory(&sl);
	return 0;
}	



