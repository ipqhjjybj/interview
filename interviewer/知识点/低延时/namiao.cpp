
#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
int main()
{
	typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();//计时开始
    
	int temp = 0;//这行替换成你的算法
	for(int i = 0;i < 1000000;i++)//这行替换成你的算法
		temp++;//这行替换成你的算法
 
    auto t2 = Clock::now();//计时结束
    std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<< '\n';

    std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1e+9 << '\n';
}
