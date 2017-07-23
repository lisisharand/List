#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10 //初始化表长
#define INCREMENT_SIZE 5//分配增量


typedef int Status;
typedef int Elemtype;
/*
存储结构
*/
typedef struct
{
	Elemtype *elem;//存储空间基址
	int length;	//当前长度
	int size;	//当前分配的表长大小

}SqList; //结构类型别名

/*
初始化一个空的线性表
*/
Status InitList(SqList *L)
{
	L->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
	if (!L->elem)
	{
	return ERROR;

	}
	L->length = 0;
	L->size = INIT_SIZE;
	return OK;

}


/*
销毁线性表
*/
Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;

}


/*
清空线性表
*/
Status ClearList(SqList *L)
{

	L->length = 0;
	return OK;


}


Status isEmpty (const SqList L)
{
	if (0 == L.length)
	{
	return TRUE;
	}
	else
	{
	return FALSE;
	}

}


/*获取长度*/

Status getLength(const SqList L)
{
	return L.length;

}


/*根据位置获取元素*/
Status GetElem(const SqList L,int i,Elemtype *e)
{
	if(i < 1|| i > L.length)
	{
	return ERROR;

	}
	*e = L.elem[i-1];
	return OK;


}


Status InsertElem(SqList *L,int i,Elemtype e)
{
	Elemtype *new;
	if(i < 1|| i >L->length +1)
	{
	return ERROR;
	}
	if (L->length >=L->size)
	{
	new = (Elemtype *)realloc(L->elem,(L->size + INCREMENT_SIZE)* sizeof(Elemtype)
);
	if (!new)
	{
	return ERROR;
	}
	L->elem = new;
	L->size +=INCREMENT_SIZE;
	Elemtype *p = &L->elem[i-1];
	Elemtype *q = &L->elem[L->length -1];
	for (; q>=p;q --)
	{
	*(q+1)= *q;
	
	}
	*p = e;
	++L->length;
	return OK;


	}


}




int main()
{
	SqList L;
	if (InitList(&L))
	{
	Elemtype e;
	printf("init_success\n");
	int i;
	for (i =0;i <10;i++)
	{
		InsertElem(&L,i+1,i);	


	}
	printf("length is %d\n",getLength(L));
	if (GetElem(L,1,&e)){
	printf("The first element is %d\n",e);


	}




	
	}





	/*if (DestroyList(&L))

	{
		printf("\ndestroy_success\n");


	}





}
