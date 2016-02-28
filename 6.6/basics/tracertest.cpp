#include <iostream>
#include <algorithm>
#include "tracer.hpp"

int main()
{
	// 标准样本资料源
	SortTracer input[] = {7, 3, 5, 6, 4, 2, 0, 1, 9, 8};

	// 列印起始值
	for (int i = 0; i < 10; ++i)
	{
		std::cerr << input[i].val() << ' ';
	}
	std::cerr << std::endl;

	// 记录起始值
	long created_at_start = SortTracer::creations();
	long max_live_at_start = SortTracer::max_live();
	long assigned_at_start = SortTracer::assignments();
	long compared_at_start = SortTracer::comparisons();

	// 执行演算法
	std::cerr << "----[ Start std::sort() ]---------------" << std::endl;
	std::sort<>(&input[0], &input[9] + 1);
	std::cerr << "----[ End std::sort() ]--------------" << std::endl;

	// 检验结果
	for (int i = 0; i < 10; ++i) {
		std::cerr << input[i].val() << ' ';
	}
	std::cerr << std::endl << std::endl;

	// 最终报告
	std::cerr << "std::sort() of 10 SortTracer's"
		<< " was performed by: " << std::endl << ' '
		<< SortTracer::creations() - created_at_start
		<< " temporary tracers" << std::endl << ' '
		<< "up to "
		<< SortTracer::max_live()
		<< " tracers at the same time ("
		<< max_live_at_start << " before)" << std::endl << ' '
		<< SortTracer::assignments() - assigned_at_start
		<< " assignments" << std::endl << ' '
		<< SortTracer::comparisons() - compared_at_start
		<< " comparisons" << std::endl << std::endl;

	return 0;
}
