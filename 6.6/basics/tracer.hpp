#include <iostream>

class SortTracer
{
private:
	int value_;			// 用来的排序的整数
	int generation_;		// 此追踪器的生成个数
	static long n_created_;		// 建构式被呼叫的次数
	static long n_destroyed_;	// 解构式被呼叫的次数
	static long n_assigned_;		// 赋值次数
	static long n_compared_;	// 比较次数
	static long n_max_live_;	// 同一时间最多存在几个objects

	// 重新计算[同一时间最多存在几个objects]
	static void update_max_live()
	{
		if (n_created_ - n_destroyed_ > n_max_live_) {
			n_max_live_ = n_created_ - n_destroyed_;
		}
	}

public:
	static long creations()
	{
		return n_created_;
	}

	static long destructions()
	{
		return n_destroyed_;
	}

	static long assignments()
	{
		return n_assigned_;
	}

	static long comparisons()
	{
		return n_compared_;
	}

	static long max_live()
	{
		return n_max_live_;
	}

public:
	// 构建式(constructor)
	SortTracer(int v = 0) : value_(v), generation_(1)
	{
		++n_created_;
		update_max_live();
		std::cerr << "SortTracer #" << n_created_
			<< ", created generation " << generation_
			<< " (total: " << n_created_ - n_destroyed_
			<< ")" << std::endl;
	}

	// copy构建式(copy constructor)
	SortTracer(SortTracer const& b)
		: value_(b.value_), generation_(b.generation_ + 1)
	{
		++n_created_;
		update_max_live();
		std::cerr << "SortTracer #" << n_created_
			<< ", copied as generation " << generation_
			<< " (total: " << n_created_ - n_destroyed_
			<< ")" << std::endl;
	}

	// 解构式(destructor)
	~SortTracer()
	{
		++n_destroyed_;
		update_max_live();
		std::cerr << "SortTracer generation " << generation_
			<< " destroyed (total: "
			<< n_created_ - n_destroyed_ << ")" << std::endl;
	}

	// 赋值(assignment)
	SortTracer& operator= (SortTracer const& b)
	{
		++n_assigned_;
		std::cerr << "SortTracer assignment #" << n_assigned_
			<< " (generation " << generation_
			<< " + " << b.generation_
			<< ")" << std::endl;
		value_ = b.value_;
		return *this;
	}

	// 比较(comparison)
	friend bool operator < (SortTracer const& a,
		SortTracer const& b)
	{
		++n_compared_;
		std::cerr << "SortTracer comparison #" << n_compared_
			<< " (generation " << a.generation_
			<< " < " << b.generation_
			<< ")" << std::endl;
		return a.value_ < b.value_;
	}

	int val() const
	{
		return value_;
	}
};
