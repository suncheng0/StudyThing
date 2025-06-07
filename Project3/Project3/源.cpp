template<class type>
struct _type_traits {
	//泛化
};
template<> struct _type_traits<int> {
	//特化
};

template<class T,class Alloc >
class vector {};
//个数偏特化
template<class Alloc>
class vector<bool, Alloc> {};

template<class Iterator>
struct iterator_traits {};
//范围偏特化
template<class T>
struct iterator_traits<T*> {};
template<class T>
struct iterator_traits<const T*> {};