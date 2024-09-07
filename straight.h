#ifndef KUMATARO_INCLUDE_STRAIGHT_H
#define KUMATARO_INCLUDE_STRAIGHT_H

#include <array>
#include <vector>
#include <bit>


namespace kuma::impl
{
	//POT = Power Of Two

	template <class T>
	constexpr void sort_2_ToOut(const T* in, T* out)noexcept
	{
		if(in[0] <= in[1])
		{
			out[0] = in[0];
			out[1] = in[1];
		}
		else
		{
			out[0] = in[1];
			out[1] = in[0];
		}
	}

	template <class T>
	constexpr void sort_2_ToIn(T* inout)noexcept
	{
		if(inout[0] > inout[1])
		{
			const T tmp = inout[0];
			inout[0] = inout[1];
			inout[1] = tmp;
		}
	}

	template <class T>
	constexpr void merge_POT_ToOut(const T* in, T* out, size_t nHalf)noexcept
	{
		const T* const sortedL = in;
		const T* const sortedR = in + nHalf;
		size_t lMin = 0, rMin = 0, oMin = 0, lMax = nHalf - 1, rMax = nHalf - 1, oMax = 2 * nHalf - 1;
		for(size_t c = nHalf; c; --c)
		{
			out[oMin++] = sortedL[lMin] <= sortedR[rMin] ? sortedL[lMin++] : sortedR[rMin++];
			out[oMax--] = sortedL[lMax] > sortedR[rMax] ? sortedL[lMax--] : sortedR[rMax--];
		}
	}

	template <class T>
	void mergeSort_POT_ToIn(T* inout, T* aux, size_t n)noexcept;

	template <class T>
	void mergeSort_POT_ToOut(T* in, T* out, size_t n)noexcept
	{
		if(n == 2)
		{
			sort_2_ToOut(in, out);
			return;
		}
		const size_t nHalf = n / 2;
		mergeSort_POT_ToIn(in, out, nHalf);
		mergeSort_POT_ToIn(in + nHalf, out, nHalf);
		merge_POT_ToOut(in, out, nHalf);
	}

	template <class T>
	void mergeSort_POT_ToIn(T* inout, T* aux, size_t n)noexcept
	{
		if(n == 2)
		{
			sort_2_ToIn(inout);
			return;
		}
		const size_t nHalf = n / 2;
		mergeSort_POT_ToOut(inout, aux, nHalf);
		mergeSort_POT_ToOut(inout + nHalf, aux + nHalf, nHalf);
		merge_POT_ToOut(aux, inout, nHalf);
	}

	template <class T>
	constexpr void merge_N_ToInR(const T* auxL, T* inout, size_t nL, size_t nR)noexcept
	{
		const T* const inoutR = inout + nL;
		if(auxL[nL - 1] <= inoutR[nR - 1])
		{
			size_t l = 0, r = 0, o = 0;
			while(l < nL)
			{
				inout[o++] = auxL[l] <= inoutR[r] ? auxL[l++] : inoutR[r++];
			}
		}
		else
		{
			size_t l = 0, r = 0, o = 0;
			while(r < nR)
			{
				inout[o++] = auxL[l] <= inoutR[r] ? auxL[l++] : inoutR[r++];
			}
			while(l < nL)
			{
				inout[o++] = auxL[l++];
			}
		}
	}

	template <class T>
	void mergeSort_N_ToIn(T* inout, T* aux, size_t n)noexcept
	{
		if(n == 1)
		{
			return;
		}
		const size_t nL = std::bit_floor(n);
		const size_t nR = n & ~nL;// n - nL
		if(nR == 0)
		{
			mergeSort_POT_ToIn(inout, aux, nL);
			return;
		}
		mergeSort_POT_ToOut(inout, aux, nL);
		mergeSort_N_ToIn(inout + nL, aux + nL, nR);
		merge_N_ToInR(aux, inout, nL, nR);
	}

	template <class T>
	constexpr void mergeSort(T* arr, size_t n)noexcept
	{
		switch(n)
		{
		case 0:
		case 1:
			return;

		case 2:
			sort_2_ToIn(arr);
			return;
		}
		const size_t nL = std::bit_floor(n - 1);
		const size_t nR = n - nL;
		{
			T* const aux = new T[nL];
			mergeSort_N_ToIn(arr + nL, aux, nR);
			mergeSort_POT_ToOut(arr, aux, nL);
			merge_N_ToInR(aux, arr, nL, nR);
			delete[]aux;
		}
	}
}

namespace kuma
{
	using namespace impl;

	template <class T>
	void sort(T* const arr, const size_t n)noexcept
	{
		mergeSort(arr, n);
	}

	template <std::contiguous_iterator Iterator>
	inline void sort(Iterator begin, Iterator end)noexcept
	{
		sort(&(*begin), std::distance(begin, end));
	}

	template <class T, size_t N>
	inline void sort(std::array<T, N>& arr)noexcept
	{
		sort(arr.begin(), arr.end());
	}

	template <class T>
	inline void sort(std::vector<T>& arr)noexcept
	{
		sort(arr.begin(), arr.end());
	}
}


#endif