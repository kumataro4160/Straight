export module straight.sort:merge_sort;

namespace straight
{
	constexpr size_t floorPowOf2(size_t n)noexcept
	{
		n = (n & 0xffffffff00000000ULL) ? (n & 0xffffffff00000000ULL) : n;
		n = (n & 0xffff0000ffff0000ULL) ? (n & 0xffff0000ffff0000ULL) : n;
		n = (n & 0xff00ff00ff00ff00ULL) ? (n & 0xff00ff00ff00ff00ULL) : n;
		n = (n & 0xf0f0f0f0f0f0f0f0ULL) ? (n & 0xf0f0f0f0f0f0f0f0ULL) : n;
		n = (n & 0xccccccccccccccccULL) ? (n & 0xccccccccccccccccULL) : n;
		n = (n & 0xaaaaaaaaaaaaaaaaULL) ? (n & 0xaaaaaaaaaaaaaaaaULL) : n;
		return n;
	}
}

namespace straight
{
	template <class T>
	inline void _sort_2_ToOut(const T* in, T* out)noexcept
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
	inline void _sort_2_ToIn(T* inout)noexcept
	{
		if(inout[0] > inout[1])
		{
			const T tmp = inout[0];
			inout[0] = inout[1];
			inout[1] = tmp;
		}
	}

	template <class T>
	inline void _merge_POT_ToOut(const T* in, T* out, size_t nHalf)noexcept
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
	void _mergeSort_POT_ToIn(T* inout, T* aux, size_t n)noexcept;

	template <class T>
	void _mergeSort_POT_ToOut(T* in, T* out, size_t n)noexcept
	{
		if(n == 2)
		{
			_sort_2_ToOut(in, out);
			return;
		}
		const size_t nHalf = n / 2;
		_mergeSort_POT_ToIn(in, out, nHalf);
		_mergeSort_POT_ToIn(in + nHalf, out, nHalf);
		_merge_POT_ToOut(in, out, nHalf);
	}

	template <class T>
	void _mergeSort_POT_ToIn(T* inout, T* aux, size_t n)noexcept
	{
		if(n == 2)
		{
			_sort_2_ToIn(inout);
			return;
		}
		const size_t nHalf = n / 2;
		_mergeSort_POT_ToOut(inout, aux, nHalf);
		_mergeSort_POT_ToOut(inout + nHalf, aux + nHalf, nHalf);
		_merge_POT_ToOut(aux, inout, nHalf);
	}

	template <class T>
	inline void _merge_N_ToInR(const T* auxL, T* inout, size_t nL, size_t nR)noexcept
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
	void _mergeSort_N_ToIn(T* inout, T* aux, size_t n)noexcept
	{
		if(n == 1)
		{
			return;
		}
		const size_t nL = floorPowOf2(n);
		const size_t nR = n & ~nL;// n - nL
		if(nR == 0)
		{
			_mergeSort_POT_ToIn(inout, aux, nL);
			return;
		}
		_mergeSort_POT_ToOut(inout, aux, nL);
		_mergeSort_N_ToIn(inout + nL, aux + nL, nR);
		_merge_N_ToInR(aux, inout, nL, nR);
	}
}

export namespace straight
{
	template <class T>
	void mergeSort(T* arr, size_t n)noexcept
	{
		switch(n)
		{
		case 0:
		case 1:
			return;

		case 2:
			_sort_2_ToIn(arr);
			return;
		}
		const size_t nL = floorPowOf2(n - 1);
		const size_t nR = n - nL;
		{
			T* const aux = new T[nL];
			_mergeSort_N_ToIn(arr + nL, aux, nR);
			_mergeSort_POT_ToOut(arr, aux, nL);
			_merge_N_ToInR(aux, arr, nL, nR);
			delete[]aux;
		}
	}
}