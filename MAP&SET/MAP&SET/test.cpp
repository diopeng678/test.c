#define _CRT_SECURE_NO_WARNINGS

//MAP 不支持重复的key 但是可以有重复的value
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map <string, string> m;
	m["matou1"] = "zhangsan";
	m["weijiale"] = "choujiba";
	m = {
		{"matou1", "zhangsan"},
		{"weijiale", "choujiba"},
		{"matou2", "lisi"}
	};
	for (auto& a : m)
	{
		cout << a.first << " " << a.second << endl;
	}

	map<string, string> dict;
	pair<string, string> kv1("first", "第一");
	dict.insert(kv1);
	dict.insert(pair<string, string>("second", "第二"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert({ "auto","自动" }); // 最简洁
	//顺序是根据key的大小来排序的 英语字母是根据ASCII码来排序的
	//其中自动是最后插入的 但是它的key是auto，a的ASCII码是97排到最前面,所以它排在了第一个

	for (auto& kv : dict) {
		cout << kv.first << " : " << kv.second << endl;
	}

	// 迭代器 -> 用法
	auto it = dict.begin();
	cout << it->first << " : " << it->second << endl;

	//主要有三种用法
	//不存在->插入+修改
	//存在->修改
	dict["first"] = "第一个"; // 存在->修改
	cout << dict["first"] << endl;

	dict["third"] = "第三"; // 不存在->插入+修改
	cout << dict["third"] << endl;

	//其中还有multimap
	/*multimap 在 <map> 头文件中：

		key 可重复，不去重
		不支持 operator[]：key 不唯一，无法确定返回哪个 value
		find(key)：返回中序第一个匹配项
		count(key)：返回真实重复次数
		适用：一对多映射（如一个姓名对应多个电话）
	*/
	multimap<string, string> mm;
	mm.insert(make_pair("matou1", "zhangsan"));
	mm.insert(make_pair("matou1", "lisi"));
	mm.insert(make_pair("weijiale", "choujiba"));
	mm.insert(make_pair("weijiale", "choudiaomao"));

	for (auto& jj : mm) {
		cout << jj.first << " : " << jj.second << endl;
	}

	return 0;
	//map和multimap 的迭代器是双向迭代器，支持++和--操作，可以正向和反向遍历容器
}


