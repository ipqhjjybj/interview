#vector

// 方法
empty(); //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
push_back(ele); //尾部插入元素ele。
emplace_back：与push_back的区别为，如果要push pair。push_back({1,1}) 需要{}，emplace_back（1,1）
pop_back(); //删除最后一个元素
insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
end(): //返回一个指向当前vector末尾元素的下一位置的迭代器.要访问末尾元素,需要先将此迭代器减1。

// 调用函数
reverse(a.begin(), a.end()); // 逆转
return *max_element(a.begin(), a.end()) ;  返回vector，maxF中最大的元素方法
int sum = accumulate(vec.begin() , vec.end() , 42);  // 累加，42为初值，accumulate定义在#include<numeric>中。
sort(nums.begin(), nums.end(), greater<int>());    // 基础升序排列
sort(vec.begin(), vec.end(), [](const vector<int> & a, const vector<int> & b) {return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);}); 
// vec为二维vector。根据第一个降序排序，第一个相等的话按第二个升序
// 赋初值的方法
m=(int)grid.size(), n=(int)grid[0].size()  // m*n的矩阵
int arr[5] = {0,1,2,3,4}   // 没赋值的默认初始化为0。初始化数组而不是vector
int dis[10][10];    // 矩阵数组初始化
memset(dis, -1, sizeof(dis));  // 初始化，都赋为-1。等同两个for循环赋值

vector<int> dp(5, 1);  // 初始化vector为[1,1,1,1,1]
vector<vector<int>> f(m, vector<int>(n));  创建一个m*n的矩阵f
vector的遍历方式
for (int i = 0; i < vec.size(); ++i)  // 基础遍历  for (auto i:vec)
//第二种遍历方式： 迭代器it可以看做指针
for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {  // 可以用auto		
      cout << *it << endl;}   // 解引用就是该数
//第三种遍历方式：
//使用STL提供标准遍历算法  头文件 algorithm
for_each(v.begin(), v.end(), MyPrint);