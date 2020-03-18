#include <stdio.h>
#include <iostream>
#define DataType int
using namespace std;
enum Status{SUCCESS,FAIL,RANGE_ERROR,OVER_FLOW,FULL,EMPTY};//SUCCESS成功 FAIL失败 FULL表满
class SeqList
{
private:
	DataType *data;//动态数组
	int len;//当前位置
	int maxLen;//最多存放数量
public:
	SeqList(int size);//带参构造函数
	~SeqList();//析构函数
	int  length() const;
	Status  getDate(int i,DataType &d) const;//按位置查找 位置与下标有关 位置-1=下标
	Status  locateDate(DataType x) const;//按值查找
	Status  insertDate(const DataType &item, int i);//在第i个位置插入一个元素
	Status  deleteDate(int i,DataType &d);//删除第i个元素
    Status  deleteRange(int i,int j);//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
	void display();
};
SeqList::SeqList(int size)
{
    data = new DataType[size];//动态分配数组
    maxLen=size;
	len=0;
}
SeqList::~SeqList()
{
	delete []data;
}
int SeqList::length() const
{}
//按位置查找
Status SeqList::getDate(int i,DataType &d) const
{
    if(i-1<=len)
    {
        d=data[i-1];
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
    
}
//按值查找
Status SeqList::locateDate(int x) const
{
    int j;
    for(j=0;j<len-1;j++)
    {
        if (x==data[j])
        {
            cout<<"找到了下标为："<<j<<endl;
            break;
            return SUCCESS;
        }
        if(j==len)
        {
            cout<<"没找到"<<endl;
            return FAIL;
        }
    }
}
//在第i个位置插入一个元素
Status  SeqList::insertDate(const DataType &item, int i)
{
    int j;
    if(len==maxLen)//判断表是否已满
        return FULL;
    else
    {
        if(i<0||i>len+1)//判断i是否合法
            return RANGE_ERROR;
        else
        {
            for(j=len;j>=i;j--)
                data[j]=data[j-1];//让位
            data[j]=item;//插入
            len++;
            return SUCCESS;
        }
    }
}
//删除第i个元素
Status  SeqList::deleteDate(int i,DataType &d)
{
    return SUCCESS;
}
//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
Status  SeqList::deleteRange(int i,int j)
{
    return SUCCESS;
}
int main()
{
    SeqList *sl=new SeqList(10);
    DataType i=7;
    DataType &item=i;
    if(sl->insertDate(item,1)==0)
        cout<<"插入成功"<<endl;
    system("pause");
    return 0;
};