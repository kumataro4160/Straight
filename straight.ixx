module;

#include <vector>

export module straight;

export namespace kuma
{
	template <class T>
	void sort(T* const arr, const size_t n)noexcept;

	template <class T, size_t N>
	inline void sort(std::array<T, N>& arr)noexcept
	{
		sort(&arr[0], N);
	}

	template <class T>
	inline void sort(std::vector<T>& arr)noexcept
	{
		sort(&arr[0], arr.size());
	}

	template <std::contiguous_iterator Iterator>
	inline void sort(Iterator begin, Iterator end)noexcept
	{
		sort(&(*begin), std::distance(begin, end));
	}
}

import :merge_sort;

namespace kuma
{
	template <class T>
	void sort(T* const arr, const size_t n)noexcept
	{
		mergeSort(arr, n);
	}
}