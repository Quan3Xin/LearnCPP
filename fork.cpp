// 生成一个进程
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <thread>


using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if(v1 < v2)return -1;
    if(v1 > v2)return 1;
    return 0;
}
void hello(int a)
{
    while(1){
    cout << "Hello, this's form the child thread!" << "\n" << a
        ;
    sleep(4) ;
    }
}
int main()
{
    pid_t childID;
    childID = fork(); // 生成一个进程
    cout << childID << '\n'<< endl;
    int a,b;
    a = 19;
    b = 23;
    int c = compare(a,b);
    cout << c<<endl;
    if(childID == 0){
        cout << "This is the child process\n";
    } else {
        cout << "This is the parent process\n";
    }
    // 使用线程管理
    
    thread t(hello, a);
    
    t.join();
    cout << "This !!!!!!!!!!!\n";
    return 0;

}
