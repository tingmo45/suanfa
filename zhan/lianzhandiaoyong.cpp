#include<iostream>
using namespace std; 
void menu(){
    cout<<"1.进栈"<<endl;
    cout<<"2.出栈"<<endl;
    cout<<"3.获取栈顶元素"<<endl;
    cout<<"4.栈置空"<<endl;
    cout<<"5.退出"<<endl;
} 
template<class T>
void function(int num,LinkedStack<T> *ls){
    switch(num){
        int x;
        case 1:
            cin>>x;
            ls->push(x);
            break;
        case 2:
            ls->pop(x);
            break;
        case 3:
            ls->getTop(x);
            cout<<x<<endl;
            break;
        case 4:
            ls->makeEmpty();
            break;
        case 5:
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