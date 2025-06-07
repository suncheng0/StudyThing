#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;
int main() {
	int ia[6] = { 27,210,12,47,109,83 };
	vector<int, allocator<int>>vi(ia, ia + 6);
	cout <<count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40)));

	for (int i : {2, 3, 5, 7, 9, 13, 17, 19}) {
		cout << i << endl;
	}
	vector<double>vec;
	for (auto elem : vec) {
		cout << elem << endl;
	}
	for (auto& elem : vec) {
		elem *= 3;
	}

	list<string>c;
	list<string>::iterator ite;
	ite = ::find(c.begin(), c.end(), target);
	return 0;
}