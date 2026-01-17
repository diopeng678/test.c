#include"sequlist.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//顺序表的销毁
void SLDestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//插入数据之前看空间够不够
void CheckCapacity(SL* ps)
{    //申请空间用realloc
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail !");
		}
		//空间申请成功
		ps->arr = tmp;
		ps->capacity = newcapacity;

	}
}

//尾插法
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);//等价于if(ps==NULL)return;
	//检查空间
	CheckCapacity(ps);
	//插入数据
	ps->arr[ps->size] = x;
	ps->size++;
}
//头插法	
void SLPushFront(SL* ps, SLDataType x)
{

	assert(ps);
	CheckCapacity(ps);
	//数据后移
	for(int i=ps->size-1;i>=0;i--)
	{
		ps->arr[i+1]=ps->arr[i];
	}
	//插入数据
	ps->arr[0] = x;
	ps->size++;
}

//打印顺序表
void SLPrint(SL* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}







