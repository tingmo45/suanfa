#include<iostream>
using namespace std; 
template<class T>
struct LinkNode{//链表节点 
    T data;
    LinkNode *link;
    LinkNode(const T& args,LinkNode<T> *ptr=NULL){
        data=args;
        link=ptr;
    }
};
template<class T>
class LinkedStack{
        LinkNode<T> *top;
    public:
        LinkedStack(){
            top=NULL;     
        }
        ~LinkedStack(){
            makeEmpty();
        }
        void push(const T& x){//进栈 
            top=new LinkNode<T>(x,top);
        }
        bool pop(T& x){//出栈 
            if(isEmpty())
                return false;
            LinkNode<T> *p=top;
            top=top->link;
            x=p->data;
            delete p;
        }
        bool getTop(T& x)const{//返回栈顶元素 
            if(isEmpty())
                return false;
            x=top->data;
            return true;
        }
        bool isEmpty()const{ 
            return (top==NULL)?true:false;
        }
        int getSize()const{
            LinkNode<T> *p=top;
            int k=0;
            while(p!=NULL){
                p=p->link;
                k++;
            } 
            return k;
        }
        void makeEmpty(){//栈置空 
            LinkNode<T> *p;
            while(top!=NULL){
                p=top;
                top=top->link;
                delete p;
            }
        }
        void display()//输出栈内数据元素
        {
            int z=1;
            LinkNode<T> *p=top;
            if(isEmpty()==false)
           {
                while(p!=NULL)
                {
                    //p=p->data;
                    cout<<"第"<<z++<<"数据元素:"<<p->data<<endl;
                    p=p->link;
                }
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
void function(int num,LinkedStack<T> *ls){
    switch(num){
        int x;
        case 1:
            cout<<"请输入进栈元素"<<endl;
            cin>>x;
            ls->push(x);
            cout<<"-------------"<<endl;
            break;
        case 2:
            ls->pop(x);
            cout<<"-------------"<<endl;
            break;
        case 3:
            cout<<"栈顶元素为："<<endl;
            ls->getTop(x);
            cout<<x<<endl;
            cout<<"-------------"<<endl;
            break;
        case 4:
            ls->makeEmpty();
            cout<<"-------------"<<endl;
            break;
        case 5:
            ls->display();
            cout<<"-------------"<<endl;
            break;
        case 6:
            exit(1); 
            break;
    }
}
int main(int argc, char** argv) {
    LinkedStack<int> *ls=new LinkedStack<int>;
    int num;
    while(true){
        menu();
        cin>>num;
        function(num,ls);
    } 
    delete ls;
    return 0; 
}