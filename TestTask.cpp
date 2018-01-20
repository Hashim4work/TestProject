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





void main()
{
	vector<double> v({ 1.1,2.2,3,3.3 });
	cout << "after map function" << endl;
	v = map(v);
	for (int i = 0; i <= v.size() - 1; i++)
	{
		cout << v.at(i) << endl;
	}
}