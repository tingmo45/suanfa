#include<iostream>
using namespace std; 
typedef int DataType; 
enum Status{ SUCCESS, FAIL, RANGE_ERROR, OVER_FLOW, EMPTY };

struct Node
{
public:
    DataType data;//数据域
    Node * next;//指针域
};

class LinkList
{
public:
    LinkList ();//构建一个单链表;  
    ~LinkList ();//销毁一个单链表; 
    void TravalLinkList();//遍历线性表   
    int GetLength();//获取线性表长度 
    int LocateData( const DataType & data ) const;  
    Status GetData( int i, DataType & data ) const; 
    Status InsertElemAtIndex ( int i, const DataType & data );  
    Status DeleteElemAtIndex ( int i, DataType & data );

private:
    Node * head;//头指针
    int length;
};
//初始化单链表创建空白头结点
LinkList :: LinkList ()
{
    head = new Node;
    head->data = 0;//将头结点的数据域定义为0
    head->next = NULL;//头结点的下一个定义为NULL
    length = 0;
}

//销毁单链表
LinkList :: ~LinkList ()
{
    Node * temp = head;
    while ( temp != NULL )
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
//遍历单链表
void LinkList :: TravalLinkList ()
{
    if ( length == 0 )
    {
        cout << "EMPTY" << endl;
        return;
    }
    Node * temp = head->next;
    while ( temp != NULL )
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//获取单链表的长度
int LinkList :: GetLength ()
{
    return length;
}
//查找结点data
int LinkList :: LocateData ( const DataType & data ) const
{
    Node * temp = head->next;
    int i = 1;
    while ( temp != NULL )
    {
        if ( data == temp->data )
        {
            return i;
        }
        temp = temp->next;
        ++i;
    }
    return -1;
}
//查找第i个结点
Status LinkList :: GetData ( int i, DataType & data ) const
{
    if ( length > 0 && i >= 1 && i <= length )//判断位置合法性
    {
        Node * temp = head->next;
        int j = 1;
        while ( temp != NULL && j++ < i )
        {
            temp = temp->next;
        }
        data = temp->data;
        return SUCCESS;
    }
    return FAIL;
}
//在指定位置插入指定元素
Status LinkList :: InsertElemAtIndex ( int i, const DataType & data )
{
    if ( i >= 1 && i <= length + 1 )//判断位置合法性
    {
        Node * temp = head;
        Node * insertNode = new Node;
        int j = 1;
        while ( temp != NULL && j++ < i )
        {
            temp = temp->next;
        }
        insertNode->data = data;
        insertNode->next = temp->next;
        temp->next = insertNode;
        length++;
        return SUCCESS;
    }
    return FAIL;
}
//删除指定的数据
Status LinkList :: DeleteElemAtIndex ( int i, DataType & data )
{
    if ( length > 0 && i >= 1 && i <= length )//判断位置合法性
    {
        Node * temp = head;
        int j = 1;
        while ( temp != NULL && j++ < i )
        {
            temp = temp->next;
        }
        Node * deleteNode = temp->next;
        data = deleteNode->data;
        temp->next = temp->next->next;
        delete deleteNode;
        length--;
        return SUCCESS;
    }
    return FAIL;
}
int main()
{
	LinkList *sl = new LinkList();
	 DataType i=7;
    DataType &item=i;
    for(int k=1;k<=5;k++)
    {
        cout<<"输入插入元素"<<endl;
        cin>>item;
        sl->InsertElemAtIndex(k,item);
    }
	cout<<"数据元素如下"<<endl;
	sl->TravalLinkList();
	DataType d;
	sl->GetData(3,d);
	sl->LocateData(3);
	sl->DeleteElemAtIndex(3,d);
	cout<<"删除成功！更新如下"<<endl;
	sl->TravalLinkList();
	system("pause");
    return 0;
};
