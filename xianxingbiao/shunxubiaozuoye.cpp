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
	Status  insertDate(const DataType &item);//在第i个位置插入一个元素
	Status  deleteDate(int i,DataType &d);//删除第i个元素
    Status  deleteRange(int i,int j);//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
	void display();
    //friend ostream& operator<<(ostream& out, const SeqList& sl);
};
SeqList::SeqList(int size)
{
    data = new DataType[size];//动态分配数组
    maxLen=size;
	len=5;
     data[0]=10;
     data[1]=16;
     data[2]=43;
     data[3]=55;
     data[4]=66;
    // data[5]=46;
    // data[6]=36;
    // data[7]=49;
    // data[8]=52;
    // data[9]=61;
}
SeqList::~SeqList()
{
	delete []data;
}
int SeqList::length() const
{
   return this->len;
}
//按位置查找
Status SeqList::getDate(int i,DataType &d) const
{
    if(i-1<=len)
    {
        d=data[i-1];
        cout<<"找到了值为："<<d<<endl;
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
Status  SeqList::insertDate(const DataType &item)
{
    int j;
    if(len==maxLen)//判断表是否已满
        return FULL;
    else
    {
        // if(i<0||i>len+1)//判断i是否合法
        //     return RANGE_ERROR;
        // else
        // {
            for(j=0;j<=len+1;j++)
            {
                if(item<=data[j])
                {
                    data[j+1]=data[j];//让位
                    data[j]=item;//插入
                    break;
                }
                else
                {
                    // if(item<data[len])
                    data[j-1]=data[j];//让位
                    data[j]=item;//插入
                    break;
                }
            }
            len++;
             cout<<"插入成功"<<endl;
            return SUCCESS;
        // }
    }
}
//删除第i个元素
Status  SeqList::deleteDate(int i,DataType &d)//i要删除的位置 d将要删除的值
{
    if(i<=0||i>len)//判断i是否合法
        return RANGE_ERROR;
    else
    {
        d=data[i-1];
        for(int j=i-1;j<len;j++)
            {
                data[j]=data[j+1];//移位
            }
                len--;
                cout<<"第"<<i<<"个元素删除成功,数据为："<<d<<endl;
                
        return SUCCESS;
    }
}
//删除顺序表中从第i个位置开始（包括i）到第j个位置（包括j）结束的所有数据元素
Status  SeqList::deleteRange(int i,int j)
{
    int a=0;//记录位移次数
    int q=data[i-1];
    int f=data[j-1];
    if(i<=0&&j<=0&&i>len&&j<=len)//判断i和j是否合法
        return RANGE_ERROR;
    else
    {
        for(int z=i-1;z<=len;z++)
        {
            if(data[z]>=data[j-1])
            { 
                a++;//记录位移次数
            }
            data[z]=data[z+1];//移位
        }
                len=len-a;
                cout<<"第"<<i<<"至第"<<j<<"个元素删除成功,数据为："<<q<<f<<endl;
        return SUCCESS;
    }
}
void SeqList::display()
{
    cout<<"数组元素"<<endl;
   for(int j=0;j<len;j++)
        {cout<<"第"<<j+1<<"数组元素"<<data[j]<<endl;}
        cout<<"当前数组长度"<<length()<<"最大数组长度"<<maxLen<<endl;
}
int main()
{
    SeqList *sl=new SeqList(10);
    DataType i=90;
    DataType &item=i;
     sl->display();
    // sl->insertDate(1,20);
    // sl->insertDate(2,40);
    // sl->insertDate(3,50);
    // sl->insertDate(4,70);
    // sl->insertDate(5,80);
   
    if(sl->insertDate(item)==0)
        cout<<"插入成功"<<endl;
        sl->display();
        // DataType q;
        // sl->deleteDate(1,q);
        // cout<<"执行删除后"<<endl;
        // sl->display();
        // cout<<sl->getDate(2,q);
        // cout<<sl->locateDate(2);
        //  cout<<sl->deleteRange(2,3);
        //  cout<<"执行删除后"<<endl;
        // sl->display();
        // cout<<sl<<endl;
        system("pause");
    return 0;
};