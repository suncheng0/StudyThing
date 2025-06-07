#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
using namespace std;
//////////////inserter适配器
//普通的copy函数
int myints[] = { 10,20,30,40,50,60,70 };
vector<int>myvec(7);
copy(myints, myints + 7, myvec.begin());
//用了inserter的copy函数
list<int>foo, bar;
for (int i = 1; i <= 5; i++) {
	foo.push_back(i);
	bar.push_back(i * 10);
}//定义两个链表
list<int>::iterator it = foo.begin();
advance(it, 3);
copy(bar.begin(), bar.end(), inserter(foo, it));
//
template<class InputIterator,class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
	while (first != last）{
		*result = *first;
		++result;
		++first;
	}//copy函数是采用赋值的形式
	return result;
}

template<class Container,class Iterator>
inline insert_iterator<Container> inserter(Container& x, Iterator i) {
	typedef typename Container::iterator iter;
	return insert_iterator<Container>(x, iter(i));
}//返回值是一个Inserter_iterator<Container>类的临时对象

template<class Container>
class insert_iterator {
protected:
	Container* container;
	typename Container::iterator iter;
public:
	typedef output_iterator_tag iterator_category;
	insert_iterator(Container& x, typedef Container::iterator i) :container(&x), iter(i) {}
	insert_iterator<Container>& operator=(const typename Contianer::value_type& value) {
		iter = container->insert(iter, value);
		++iter;
		return *this;
	}
	insert_iterator<Container>& operator*() {
		return *this;
	}//对inserter_iterator进行解引用* 会返回其自身 从而能够调用operator=的重载
};
