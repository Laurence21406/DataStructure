//main1-1.cpp 检验基本操作bo1-1.cpp的主函数
#include"c1.h"
typedef int ElemType;
#include"c1-1.h"//在此命令之前要定义ElemType的类型
#include"bo1-1.cpp"//在此命令之前要包括c1-1.h(因其中定义了Triplet)
int main(int argc, char *argv[])
{
  Triplet T;
  ElemType m;
  Status i;
  i = InitTriplet(T,5,7,9);
  printf("调用初始化函数后，i=%d(1:成功) T的3个值为",i);
  cout<< T[0]<<' '<< T[1]<<' '<<T[2]<<endl;
  i = Get(T ,2,m);
  if (i == OK) 
    cout <<"T的第二个值为"<<m<<endl;
  i = Put(T,2,6);
  if (i==OK)
    cout<<"将T的第二个值改为6后，T的三个值为"<<T[0]<<T[1]<<T[2]<<endl;
i=IsAscending(T); // 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变
printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
i=IsDescending(T);
printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
if((i=Max(T,m))==OK) // 先赋值再比较
cout<<"T中的最大值为"<<m<<endl;
if((i=Min(T,m))==OK)
cout<<"T中的最小值为"<<m<<endl;
DestroyTriplet(T); // 函数也可以不带回返回值
cout<<"销毁T后，T="<<T<<"(NULL)"<<endl;

				  
  return 0;
}

