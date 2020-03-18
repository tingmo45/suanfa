#include <stdio.h>
#include <iostream>
#define DataType int
using namespace std;
enum Status{SUCCESS,FAIL,RANGE_ERROR,OVER_FLOW,FULL,EMPTY};//SUCCESS成功 FAIL失败 FULL表满
class SeqList
{
private:
	DataType *data;//动态数组
	int len;//当前使用量
	int maxLen;//最多存放数量
public:
	SeqList(int size);//带参构造函数
	~SeqList();//析构函数
	int  length() const;
	Status  getDate(int i,DataType &d) const;//按位置查找
	Status  locateDate(DataType x) const;//按内容查找
	Status  insertDate(const DataType &item, int i);//插入
	Status  deleteDate(int i,DataType &d);//删除
    Status  deleteRange(int i,int j);//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
	void display();
};
SeqList::SeqList(int size)
{
    maxLen=size;
	len=0;
}
SeqList::~SeqList()
{
	delete []data;
}
int SeqList::length() const
{}
Status SeqList::getDate(int i,DataType &d) const
{
    return SUCCESS;
}
Status SeqList::locateDate(int x) const
{}
Status  SeqList::insertDate(const DataType &item, int i)
{}
Status  SeqList::deleteDate(int i,DataType &d)
{}
Status  SeqList::deleteRange(int i,int j)
{}
int main()
{
    return 0;
};