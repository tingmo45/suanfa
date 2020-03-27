#include<iostream>
using namespace std; 
typedef int DataType;
class SeqQueue
{
private:
	DataType data[MaxSize];
	int maxSize;
	int rear;
	int front;
public:
	SeqQueue();
	~SeqQueue();
	int EnQueue(DataType d);
	int DeQueue(DataType &e);
	int Front(DataType &e);  //取队首元素
    void display();
};
SeqQueue::SeqQueue()
{
	maxSize = MaxSize;
	rear = 0;
	front = 0;
}
SeqQueue::~SeqQueue()
{
    delete []data;
}

int SeqQueue::EnQueue(DataType d)//入队
{
	if ((rear + 1) % maxSize != front) //队不满才能入队
	{
		data[rear] = d;
		rear = (rear + 1) % maxSize;
		return 1;
	}
	else
	{
		cout <<"队列已满" << endl;
		return 0;
	}
	
}
int SeqQueue::DeQueue(DataType &d)//出队
{
	if (rear != front) //队不空才能出队
	{
		d=data[front];
		front =  (front + 1)% maxSize;
		return 1;
	}
	else
	{
		cout << "空队列" << endl;
		return 0;
	}
}

int SeqQueue::Front(DataType &e)//获取队头数据元素
{
	if (rear != front) //队不空才能出队
	{
		e = data[front];
		return 1;
	}
	else
	{
		cout << "空队列" << endl;
		return 0;
	}
}

void SeqQueue::display()
{
    if (rear != front) //队不空才能循环输出
	{
        for(int i=0;i<maxSize-1;i++)
		cout<<"队列元素"<<data[i]<<endl;
	}
	else
	{
		cout << "空队列" << endl;
	}
}
int main()
{
    SeqQueue sl=SeqQueue();
    DataType i;
    sl.EnQueue(7);
    sl.EnQueue(9);
    sl.EnQueue(1);
    sl.display();
    return 0;
};