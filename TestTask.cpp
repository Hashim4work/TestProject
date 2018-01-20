#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
T square(T x)
{
	return x*x;
}
template<typename func, typename T>
vector<T> map_sqr_Func(func f, const vector<T>& v)
{
	vector<T> res;
	res.reserve(v.size());
	transform(begin(v), end(v), back_inserter(res), f);
	return res;

}

template<typename T>
vector<T> map(const vector<T>&v)
{
	return map_sqr_Func(square<T>, v);
}

template<typename T>
T reducefn(T result, T value)
{
	return (result + value);
}

template<typename T>
T reduce(const vector<T>& v)
{
	T result = v.at(1) - v.at(1);
	for (T item : v)
	{
		result = reducefn(result, item);
	}
	return result;
}




void main()
{

	vector<double> v({ 1.1,2.2,3,3.3 });
	cout << "after map function" << endl;
	v = map(v);
	for (int i = 0; i <= v.size() - 1; i++)
	{
		cout << v.at(i) << endl;
	}
	vector<double> v1({ 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10 });
	/*for (int i = 0; i <= v1.size() - 1; i++)
	{
	cout << v1.at(i) << endl;
	}*/
	cout << "After reduce" << endl;
	cout << reduce(v1) << endl;


}