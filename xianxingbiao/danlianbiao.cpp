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
    length=0;//记录当前数据元素的个数
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
	int count=1; 
	Node*p=head->next;//工作指针
	while (p!=NULL)
	{
		if(data==p->data)
			break;
		else
		{
			p=p->next;
			count++;
		}
	}
	if(p!=NULL)
	{
		cout<<"找到了"<<endl;
		return count;
	}
	else
	{
		cout<<"没找到"<<endl;
		return 0;
	}
} 
//查找第i个结点
Status LinkList::GetData(int i,DataType &data) const
{
	 
	Node*p=head->next;//工作指针
	int count=1;
	if(i<1||i>length)
		return FAIL;
	else
	{
		while (count<i)
		{
			count++;
			p=p->next;
		}
			data=p->data;
			cout<<"找到了值为"<<data<<endl;
			return SUCCESS;	
	}
} 
//在指定位置插入指定元素
Status LinkList::InsertElemAtIndex(int i,const DataType &data)
{  
	Node*p=head;//第i个位置的前一个位置
	Node*q=new Node;//新建一个结点用于存放插入位置的值
	q->data=data;//被插入数据域的值
	q=p->next;//定位到第一个有效结点
	int count=1;
	if(i<1||i>length)//判断i的合法性
		return FAIL;
	else
	{
		while(count<i)
		{
			if(p->data<q->data)//判断当前指针数据域是否大于被插入数据域
			{
				p=p->next;
				count++;
			}
			else
				break;
		}
			q->next=p->next;
			p->next=q;
			length++;
			cout<<"插入成功，值为"<<p<<endl;
			return SUCCESS;
	}
} 

//删除指定的数据
Status LinkList::DeleteElemAtIndex(int i,DataType &data)
{  
	Node*p=head;//停在被删除的前一个
	Node*q=p->next;//工作指针
	int count=1;
	if(i<1||i>length)
		return FAIL;
	else
	{
		while (count<i)
		{
			count++;
			p=p->next;
		}
		q->next=p->next;
		delete p;
		length--;
			cout<<"删除成功值为"<<data<<endl;
			return SUCCESS;
			
	}
}
int main()
{
    return 0;
};
