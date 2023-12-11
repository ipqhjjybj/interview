# set和map

// set 方法
size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器
insert(elem); //在容器中插入元素。 set.emplace(nums[i]) // 也是插入
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem); //删除容器中值为elem的元素。
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数

// map方法基本与set相同
map.insert (make_pair(key, value))   // map的插入
Map[key]如果key不存在会添加key，不会抛出异常；
Map.at(key)会检查key，如果不存在会抛出异常。

// 遍历方法
unordered_map<string, vector<string>> mp;
vector<vector<string>> ans;
for (auto it = mp.begin(); it != mp.end(); ++it) {   // 哈希表的遍历方法，将set转换成vector 
    ans.emplace_back(it->second);
}

for (const auto [word, occ]: freq) {  // 哈希表的遍历方法
    if (occ == 1) {
        ans.push_back(word);
    }
}

// map的自定义排序
static int cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

sort(tmp.begin(), tmp.end(), cmp);

// set 与 vector相互转换
vector<int> v;
v = {1,2,2,3,3,4}; //建立vector
set<int> st(v.begin(), v.end()); //在构造函数中可以直接实现vector转set
v.assign(st.begin(), st.end()); //用assign实现set转vector

// map转vector
// 转为pair以对value进行排序。哈希表转vector
vector<pair<int, int>> tmp;
for(auto it = ht.begin(); it!=ht.end(); it++){
    tmp.push_back(pair<int, int>(it->first, it->second));
}