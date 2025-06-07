#include<iostream>
#include<typeinfo>
using namespace std;
template<class _Tp>
struct _List_iterator{
	typedef _Tp value_type;
};
int main() {
	cout << typeid(_List_iterator<int>::value_type).name();
	//_List_iterator<int>::value_type是一个类型名
	return 0;
}
#include<memory>
//vector

template<class T,class Alloc =alloc>
class vector {
public:
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t size_type;//size_t 是一个无符号整型，相当于unsigned int
protected:
	iterator start;
	iterator finish;
	iterator end_of_storage;
public:
	iterator begin() { return start; }
	iterator end() { return finish; }
	size_type size()const
	{
		return size_type(end() - begin();)
	}
	size_type caoacity()const
	{
		return size_tyoe(end_of_storage - begin());
	}
	bool empty()const { return begin() == end(); }
	reference operator[](size_type n)
	{
		return *(begin() + n);
	}
	reference front() { return *begin(); }
	reference back() { return *(end() - 1); }

	template<class T,class Alloc >
	void vector < T, Alloc >::insert_aux(iterator position, const T& x) {
		if (finish != end_of_storage) {
			construct(finish, x);
			++finish;
			T x_copy = x;
			copy_backward(position,finish-2,finish-1)
		}
		else
		{
			const size_type old_size = size();
			const size_type len = old_size != 0 ? old_size : 1;
			iterator new_start = data_allocator::allocate(len);
			iterator new_finish = new_start;
			try {
				new_finish = uninitialized_copy(start, position, new_start);
				construct(new_finish, x);
				++new_finish;
				new_finish = uninitialized_copy(position, finish, new_finish);
			}
			catch () {
				destory(new_start, new_finish);
				data_allocator::deallocate(new_start, len);
				throw;
			}
			deatory(begin(), end());
			deallocate();
			start = new_start;
			finish = new_finish;
			end_of_storage = new_start + len;
		}
	}
	void push_back(const T& x) {
		if (finish != end_of_storage) {
			construct(finish, x);
			++finish;
		}
		else {
			insert_aux(end(), x);
		}
	}
};
//
template<class T,class Alloc = alloc>
class  vector {
public:
	typedef T value_type;
	typedef value_type* iterator;
};
//
template<typename _Tp,std::size_t _Nm>
struct array
{
	typedef _Tp value_type;
	typedef _Tp* pointer;
	typedef value_type* iterator;

	value_type _M_instance[_Nm ? _Nm : 1];
	iterator begin()
	{
		return iterator(&_M_instance[0]);
	};
	iterator end()
	{
		return iterator(&_M_instance[_Nm]);
	};
};
//
template<class T>
struct _list_node {
	typedef void* void_pointer;
	void_pointer prev;
	void _pointer next;
	T data;
};
template<class T,class Alloc = alloc>
class list {
protected:
	typedef _list_node<T> list_node;
public:
	typedef list_node* link_type;
	typedef _list_iterator<T, T&, T*>iterator;
protected:
	link_type node;
};
template<class T,class Ref,class Ptr>
struct _list_iterator {
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef _list_node<T>* link_type;
	typedef ptrdiff_t difference_type;

	link_type node;
	referendce operator*() const { return (*node).data; }
	pointer operator->()const { return &(operator*()); }
	self& operator++()//++i
	{
		node = (link_type)((*node).next); return *this;
	}
	self operator++(int) {//i++
		self tmp = *this; ++*this; return tmp;
	}
};
//
