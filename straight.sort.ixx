module;

#include <vector>

export module straight.sort;

export namespace straight
{
	template <class T>
	void sort(T* const arr, const size_t n)noexcept;

	template <class T, size_t N>
	void sort(std::array<T, N>& arr)noexcept;

	template <class T>
	void sort(std::vector<T>& arr)noexcept;

	template <std::contiguous_iterator Iterator>
	void sort(Iterator begin, Iterator end)noexcept;
}

import :merge_sort;

namespace straight
{
	template <class T>
	void sort(T* const arr, const size_t n)noexcept
	{
		mergeSort(arr, n);
	}

	template <class T, size_t N>
	void sort(std::array<T, N>& arr)noexcept
	{
		sort(&arr[0], N);
	}

	template <class T>
	void sort(std::vector<T>& arr)noexcept
	{
		sort(&arr[0], arr.size());
	}

	template <std::contiguous_iterator Iterator>
	void sort(Iterator begin, Iterator end)noexcept
	{
		sort(&(*begin), std::distance(begin, end));
	}
}