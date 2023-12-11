#include <iostream>
#include <future>
using namespace std;

int mythread(int val) // 线程入口函数
{
    cout << "mythread start, " << "mythread id = " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // 休息5秒
    cout << "mythread end, " << "mythread id = " << std::this_thread::get_id() << endl;
    return val;
}

int main()
{
    cout << "main start, " << "main id = " << std::this_thread::get_id() << endl;
    std::future<int> result = std::async(std::launch::deferred, mythread, 180);
    cout << "main continue..." << endl;
    cout << result.get() << endl; // 在主线程中执行mythread()函数，拿到结果
    cout << "main end, " << "main id = " << std::this_thread::get_id() << endl;
    return 0;
}