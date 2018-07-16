//c2-1是动态分配的顺序存储结构
#define LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LIST_INCREMENT 2 //线性表存储空间的分配增量

struct SqList
{
	ElemType *elem;
	int length;//当前长度
	int listsize;//当前分配的存储量
};
