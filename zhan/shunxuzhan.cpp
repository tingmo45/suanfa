#include<iostream>
using namespace std; 
template<class T>//模板类
class SeqStack{
        T *element;
        int top;
        int maxSize;
        void overflow(){//栈溢出时扩大栈容量 
            T *newArray=new T[maxSize+20];
            for(int i=0;i<=top;i++){
                newArray[i]=element[i];
            }
            maxSize+=20;
            delete []element;
            element=newArray;
        }
    public:
        SeqStack(int sz=50){
            top=-1;
            maxSize=sz;
            element=new T[maxSize];
        }
        ~SeqStack(){
            delete[] element;
        }
        void push(const T& x)//进栈 
        {
            if(isFull()) 
                overflow();
            element[++top]=x;
        }
        bool pop(T& x){//出栈 
            if(isEmpty())
                return false;
            x=element[top--];
            return true;
        }
        bool getTop(T& x){//获取栈顶元素 
            if(isEmpty())
                return false;
            x=element[top];
            return true;
        }
        bool isEmpty()const//判断栈是否为空
        {
            return (top==-1)?true:false;
        }
        bool isFull()const//判断栈是否已满
        {
            return (top==maxSize-1)?true:false;
        }
        int getSize(){
            return top+1;
        }
        void makeEmpty(){//置栈空 
            top=-1;
        }
        void display()//输出栈内数据元素
        {
           if(isEmpty()==false)
           {
            for(int j=0,z=1;j<=top;j++,z++)
            cout<<"第"<<z<<"数据元素:"<<element[j]<<endl;
           }
            else
            {
                cout<<"当前栈为空"<<endl;
            }
            
        }
};
void menu(){
    cout<<"1.进栈"<<endl;
    cout<<"2.出栈"<<endl;
    cout<<"3.获取栈顶元素"<<endl;
    cout<<"4.栈置空"<<endl;
    cout<<"5.输出栈内元素"<<endl;
    cout<<"6.退出"<<endl;
} 
template<class T>
void function(int num,SeqStack<T> *ss){
    switch(num){
        int x;
        case 1:
            cout<<"请输入进栈元素"<<endl;
            cin>>x;
            ss->push(x);
            cout<<"-------------"<<endl;
            break;
        case 2:
            ss->pop(x);
            cout<<"-------------"<<endl;
            break;
        case 3:
            cout<<"栈顶元素为："<<endl;
            ss->getTop(x);
            cout<<x<<endl; 
            cout<<"-------------"<<endl;
            break;
        case 4:
            ss->makeEmpty();
            cout<<"-------------"<<endl;
            break; 
        case 5:
            ss->display();
            cout<<"-------------"<<endl;
            break; 
        default:
            exit(1);
    }
}

int main(int argc, char** argv) {
    SeqStack<int> *ss=new SeqStack<int>;
    int num;
    while(true){
        menu();
        cin>>num;
        function(num,ss);
    } 
    delete ss;
    return 0; 
}