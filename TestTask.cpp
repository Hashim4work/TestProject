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

template<typename T, typename U>
void zip_fun(const vector<T>& v, const vector<U>& u)
{
	int mi = min(v.size(), u.size());
	cout << "{";

	for (int i = 0; i <= mi - 1; i++)
	{
		cout << "(" << v.at(i) << "," << u.at(i) << ")" ",";
	}
	cout << "}";

}

template<typename T>
void zip_fun(const vector<T>& v, const vector<string> u)
{
	int mi = min(v.size(), u.size());
	cout << "{";
	for (int i = 0; i <= mi - 1; i++)
	{
		cout << "(" << v.at(i) << ",";
		printf(u.at(i).c_str());
		cout << ")" ",";
	}
	cout << "}";
}
template<typename T>
void zip_fun(const vector<string> u, const vector<T>& v)
{
	int mi = min(v.size(), u.size());
	cout << "{";
	for (int i = 0; i <= mi - 1; i++)
	{
		cout << "("; printf(u.at(i).c_str());

		cout << "," << v.at(i);
		cout << ")" ",";
	}
	cout << "}";
}
template<typename T, typename U>
void zip_fun(const vector<T>& v, const U & u)
{
	int mi = min(v.size(), u.size());
	if (typeid(u) == typeid(std::string))
	{
		cout << "{";
		for (int i = 0; i <= mi - 1; i++)
		{
			cout << "(" << v.at(i) << ",";
			cout << u[i];
			cout << ")" ",";
		}
		cout << "}";
	}
	else
		cout << "nothing";

}
template<typename T, typename U>
void zip_fun(const U &u, const vector<T> v)
{
	int mi = min(v.size(), u.size());
	if (typeid(u) == typeid(std::string))
	{
		cout << "{";
		for (int i = 0; i <= mi - 1; i++)
		{
			cout << "(" << u[i] << ",";
			//printf(u.c_str());
			cout << v.at(i);
			cout << ")" ",";
			//cout << "hello";
		}
		cout << "}";
	}
	else
		cout << "nothing";
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
	cout << "Reduce COde" << endl;
	cout << reduce(v1) << endl;
	
	cout << "ZIp COde" << endl;

	vector<int> a({ 1,2,3 });
	vector<double> b({ 1.1,2.2,3.3,4.4,5.5 });
	cout << "integer and double zip" << endl;
	zip_fun(a, b);
	vector<string> c({ "abc","ab" });
	cout<< endl << "Integer/double and strings zip" << endl;
	zip_fun(a, c);
	cout << endl << "String and integer/double";
	zip_fun(c, a);
	string s = "abc";
	cout<<endl << "integer/double and character zip" << endl;
	zip_fun(a, s);
	cout << endl << "Charater with integer/double" << endl;
	zip_fun(s, a);

}