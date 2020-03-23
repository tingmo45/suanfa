#include<iostream>
using namespace std; 
typedef int DataType;
enum Status{SUCCESS,FAIL,RANGE_ERROR,OVER_FLOW,EMPTY};
//定义结点类型
struct Node
{   public: 
	    DataType data; //数据域
	    Node  * next; //指针域
}; 
//构建一个单链表类
class LinkList
{   
	public:
		LinkList();     //构建一个单链表;    
		~LinkList(); //销毁一个单链表;    
		void TravaiLinkList(); //遍历线性表   
		int GetLength(); //获取线性表长度 
        int  LocateData(const DataType &data) const;//查找结点data
		Status  GetData(int i,DataType &data) const;//查找第i个结点
		Status  InsertElemAtIndex(int i,const DataType &data);//在指定位置插入指定元素
		Status  DeleteElemAtIndex(int i,DataType &data);//删除指定的数据
		
	private:  
		Node * head; //头指针
		int  length;
};
//初始化单链表创建空白头结点
LinkList::LinkList() 
{ 
    head = new Node; 
    head->data = 0; //将头结点的数据域定义为0
    head->next = NULL; //头结点的下一个定义为NULL
    length=0;
}
//销毁单链表
LinkList::~LinkList()
{  
	
} 
//遍历单链表
void LinkList::TravaiLinkList()
{
    
} 
//获取单链表的长度
int LinkList::GetLength()
{  
	
} 

//查找结点data
int  LinkList::LocateData(const DataType &data) const
{
	
} 
//查找第i个结点
Status LinkList::GetData(int i,DataType &data) const
{
	
} 
//在指定位置插入指定元素
Status LinkList::InsertElemAtIndex(int i,const DataType &data)
{  
	
} 

//删除指定的数据
Status LinkList::DeleteElemAtIndex(int i,DataType &data)
{  
	
}
int main()
{
    return 0;
};
