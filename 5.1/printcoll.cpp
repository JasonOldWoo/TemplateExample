#include <iostream>
#include <vector>
#include <list>

template <typename T>
void printcoll(T const& coll)
{
	/* 必须要加typename */
#if 0
	/* 错误写法 */
	T::const_iterator c_pos;	// 一个迭代器,用于巡访coll typename
	T::const_iterator c_end(coll.end());	// 末尾位置
#else
	/* 正确写法 */
	typename T::const_iterator c_pos;	// 一个迭代器,用于巡访coll typename
	typename T::const_iterator c_end(coll.end());	// 末尾位置
#endif

	for (c_pos = coll.begin(); c_pos != c_end; ++c_pos)
	{
		std::cout << *c_pos << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> ve;
	ve.push_back("1");
	ve.push_back("2");

	printcoll(ve);

	std::list<int> li;
	li.push_back(1);
	li.push_back(2);

	printcoll(li);

	return 0;
}
