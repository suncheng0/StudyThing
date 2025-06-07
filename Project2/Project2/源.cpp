#include<string>
#include<array>
#include<vector>
#include<list>
#include<forward_list>
//#include<ext\slist>
#include<deque>
#include<stack>
#include<queue>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>

#include<memory>
#include<cstddef>
#include<stdexcept>
#include<cstdio>

using namespace std;
//函数
long get_a_target_long()
{
	long target = 0;
	cout << "target(0~" << RAND_MAX << "):";
	cin >> target;
	return target;
}
string get_a_target_string()
{
	long target = 0;
	char buf[10];
	cout << "target(0~" << RAND_MAX << "):";
	cin >> target;
	snprintf(buf, 10, "%d", target);//把target的值按照%d形式输出到buf数组里面
	return string(buf);
}
int compareLongs(const void* a, const void* b) {
	return(*(long*)a - *(long*)b);
}
int compareStringss(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}
//arrar
namespace jj01
{	
	const int ASIZE = 500000;
	void test_array()
	{
		cout << "\ntest_array()....\n";
		array<long, ASIZE>c;
		clock_t timeStart = clock();
		for (long i = 0; i < ASIZE; ++i) {
			c[i] = rand();
		}
		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "array.size()=" << c.size() << endl;
		cout << "array.front()=" << c.front() << endl;
		cout << "array.back()=" << c.back() << endl;
		cout << "array.data()=" << c.data() << endl;

		long target = get_a_target_long();
		timeStart = clock();
		qsort(c.data(), ASIZE, sizeof(long), compareLongs);
		//首元素指针 数组元素数量 每个元素大小 比较函数的地址（名字）
		long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
		//要查找的目标元素的地址 已排序数组的首地址 数组的元素数量 每个元素大小 比较函数的地址（名字）
		cout << "快排和二分耗时" << (clock() - timeStart);
		if (pItem != NULL) {
			cout << "found," << *pItem << endl;
		}
		else
		{
			cout << "not founf!" << endl;
		}

	}
}//array//array
//vector
namespace jj02
{
	void test_vector(long& value) {
		cout << "\ntest_vector()...\n";
		vector<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-seconds:" << (clock() - timeStart) << endl;
		cout << "vector.size()=" << c.size() << endl;
		cout << "vector.front()=" << c.front() << endl;
		cout << "vector.back()=" << c.back() << endl;
		cout << "vector.data()" << c.data() << endl;
		cout << "vector.capacity()" << c.capacity() << endl;
		//
		string target = get_a_target_string();
		{
			timeStart = clock();
			auto pItem = ::find(c.begin(), c.end(), target);
			cout << "::find(),milli-second:" << (clock() - timeStart) << endl;
			if (pItem != c.end())
				cout << "found," << *pItem << endl;
			else
				cout << "not found" << endl;
		}
		{
			timeStart = clock();
			sort(c.begin(), c.end());
			string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStringss);
			cout << "先排序再查找" << (clock() - timeStart);
			if (pItem != NULL)
				cout << "found" << *pItem << endl;
			else
				cout << "not found" << endl;

		}
	}
}////vector
//list
namespace jj03
{
	void test_list(long& value) {
		cout << "\ntest_list().......\n";
		list<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for(long i=0;i<value;i++){
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "list.size()=" << c.size() << endl;
		cout << "list.max_size()" << c.max_size() << endl;
		cout << "list.front()=" << c.front() << endl;
		cout << "list.back()=" << c.back() << endl;
		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
					cout << "found" << *pItem << endl;
		else
			cout << "not found!" << endl;
		timeStart = clock();
		c.sort();
		cout << "排序" << (clock() - timeStart) << endl;
	}
}
//forward_list
namespace jj04
{
	void test_list(long& value) {
		cout << "\ntest_list().......\n";
		forward_list<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		//cout << "list.size()=" << c.size() << endl;
		cout << "list.max_size()" << c.max_size() << endl;
		cout << "list.front()=" << c.front() << endl;
		//cout << "list.back()=" << c.back() << endl;
		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << *pItem << endl;
		else
			cout << "not found!" << endl;
		timeStart = clock();
		c.sort();
		cout << "排序" << (clock() - timeStart) << endl;
	}
}
//deuqe
namespace jj05
{
	void test_deque(long& value) {
		cout << "\ntest_deque().......\n";
		deque<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push_front(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "deque.size()=" << c.size() << endl;
		cout << "deuqe.max_size()" << c.max_size() << endl;
		cout << "deque.front()=" << c.front() << endl;
		cout << "deque.back()=" << c.back() << endl;
		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << *pItem << endl;
		else
			cout << "not found!" << endl;
		timeStart = clock();
		::sort(c.begin(), c.end());
		cout << "排序" << (clock() - timeStart) << endl;
	}
}
//stack
namespace jj17
{
	void test_list(long& value) {
		cout << "\nstack_list().......\n";
		stack<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "stack.size()=" << c.size() << endl;
	}
}
//queue
namespace jj18
{
	void test_list(long& value) {
		cout << "\nstack_list().......\n";
		queue<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.push(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "queue.size()=" << c.size() << endl;
	}
}
//multiset
namespace jj06
{
	void test_multiset(long& value) {
		cout << "\ntest_deque().......\n";
		multiset<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multiset.size()=" << c.size() << endl;
		cout << "multiset.max_size()" << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << *pItem << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found" << *pItem << endl;
		}
		cout << "not found" << endl;
	}
}
//multimap
namespace jj07
{
	void test_multimap(long& value) {
		cout << "\ntest_multimap().......\n";
		multimap<long,string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(pair<long,string>(i,buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multiset.size()=" << c.size() << endl;
		cout << "multiset.max_size()" << c.max_size() << endl;

		int target = get_a_target_long();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found,value=" << (*pItem).second << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found,value=" << (*pItem).second << endl;
		}
		cout << "not found" << endl;
	}
}
//unordered_multiset
namespace jj07
{
	void test_unordered_multiset(long& value) {
		cout << "\ntest_unordered_multiset().......\n";
		unordered_multiset<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multiset.size()=" << c.size() << endl;
		cout << "multiset.max_size()" << c.max_size() << endl;
		cout << "multiset.bucket_count" << c.bucket_count() << endl;
		cout << "multiset.load_fastor()" << c.load_factor() << endl;
		cout << "multiset.max_load_factor()" << c.max_load_factor() << endl;
		cout << "multiset.max_bucket_count()" << c.max_bucket_count() << endl;
		for (unsigned i = 0; i < 20; i++) {
			cout << "篮子" << i << "元素个数为" << c.bucket_size(i) << endl;
		}
		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found,value=" << *pItem<< endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found,value=" << (*pItem)<< endl;
		}
		cout << "not found" << endl;
	}
}
//unordered_multimap
namespace jj08
{
	void test_unordered_multimap(long& value) {
		cout << "\ntest_unordered_map().......\n";
		unordered_multimap<long,string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(pair<long,string>(i,buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multimap.size()=" << c.size() << endl;
		cout << "multimap.max_size()" << c.max_size() << endl;

		int target = get_a_target_long();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << (*pItem).second << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found" << (*pItem).second << endl;
		}
		cout << "not found" << endl;
	}
}
//set 和unordered_set使用一模一样，只是实现方式不一样
namespace jj06
{
	void test_multiset(long& value) {
		cout << "\ntest_deque().......\n";
		set<string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(string(buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multiset.size()=" << c.size() << endl;
		cout << "multiset.max_size()" << c.max_size() << endl;

		string target = get_a_target_string();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << *pItem << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found" << *pItem << endl;
		}
		cout << "not found" << endl;
	}
}
//map 和unordered_map使用一模一样，只是实现方式不一样
namespace jj08
{
	void test_unordered_map(long& value) {
		cout << "\ntest_unordered_map().......\n";
		unordered_map<long, string>c;
		char buf[10];
		clock_t timeStart = clock();
		for (long i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				c.insert(pair<long, string>(i, buf));
			}
			catch (exception& p) {
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		cout << "milli-second:" << (clock() - timeStart) << endl;
		cout << "multimap.size()=" << c.size() << endl;
		cout << "multimap.max_size()" << c.max_size() << endl;

		int target = get_a_target_long();
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds" << (clock() - timeStart) << endl;
		if (pItem != c.end())
			cout << "found" << (*pItem).second << endl;
		else
			cout << "not found!" << endl;

		timeStart = clock();
		auto pItem = c.find(target);
		cout << "c.find(),ms:" << clock() - timeStart << endl;
		if (pItem != c.end()) {
			cout << "found" << (*pItem).second << endl;
		}
		cout << "not found" << endl;
	}
}
//allocator分配器
namespace jj20
{
	list<string, allocator<string>>c1;
	list<string, _gnu_cxx::malloc_allocator<string>>c2;
}
int main() {
	map<string, string>words;
	auto pai = words.insert({"mmaya", "完事"});
	//auto <指向插入元素或已存在元素的迭代器 , 是否插入成功>
	cout << pai.first->first << " " << pai.first->second <<
		" " << boolalpha << pai.second << endl;
	return 0;
}