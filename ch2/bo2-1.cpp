//bo2-1.cpp 顺序表示的线性表(存储结构由c2-1.h定义)的基本操作(12个),包括算法2.3,2.4,2.5,2.6
void InitList(SqList &L)
{//操作结果：构造一个空的顺序线性表L
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void Destory(SqList &L)
{// 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
}
void ClearList(SqList &L)
{//初始条件：顺序表已存在。操作结果：将L重置为空表
	L.length = 0;
}
Status ListEmpty(SqList L)
{// 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE；否则返回FALSE
	if(L.elem==0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L,int i,ElemType &e)
{
	if(i<1||i>L.length)
		return ERROR;
	e = *(L.elem + i - 1);
	return OK;
}
int LocateElem(SqList L,ElemType e,Status (*compare)(ElemType,ElemType))
{
	ElemType *p;
	int i = 1;
	p = L.elem;
	while(i<=L.length &&! compare(*p++,e))
		++i;
	if(i<=L.length)
		return i;
	else
		return 0;
}
Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
	int i = 2;
	ElemType *p = L.elem + 1;
	while(i<=L.length && *p!=cur_e)
	{
		p++;
		i++;
	}
	if(i>L.length)
		return INFEASIBLE;//操作失败
	else
	{
		pre_e = *--p;
		return OK;
	}
}
Status NextElme(SqList L, ElemType cur_e,ElemType &next_e)
{
	int i = 1;
	ElemType *p = L.elem+1;
	while(i < L.length && *p!=cur_e)
	{
		i++;
		p++;
	}
	if(i==L.length)
		return INFEASIBLE;
	else
	{
		next_e = *++p;
		return OK;
	}
}
Status ListInsert(SqList &L,int i,ElemType e)
{
	ElemType *newbase,*q,*p;
	if(i<1||i>L.length+1) // i值不合法
		return ERROR;
	if(L.length>=L.listsize)
	{
		if(!(newbase = (ElemType *)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType))))
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize+=LIST_INCREMENT;	
	}
	q = L.elem + i - 1;
	for(p=L.elem + L.length -1;p>=q;--p)
		*(p+1) = *p;//插入位置之后的元素右移
	*q = e;
	++L.length;
	return OK;
}
Status ListDelete(SqList &L,int i,ElemType &e)
{

    ElemType *p,*q;
 	if(i<1||i>L.length)
    	return ERROR;
    p = L.elem + i -1;//p为被删除元素的位置
    e = *p;
    q = L.elem + L.length - 1;//表尾元素的位置
    for(++p;p<=q;++p)
    	*(p-1) = *(p);//被删除后的元素左移
    L.length--;
    return OK;
}
void ListTraverse(SqList L,void (*vi)(ElemType &))
{
	ElemType *p;
	int i;
	p = L.elem;
	for (i = 0; i < L.length; ++i)
		vi(*p++);
	printf("\n");
}