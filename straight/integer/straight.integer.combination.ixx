export module straight.integer.combination;

import straight.integer.permutation;
import straight.integer.factorial;

export namespace flower::straight
{
	constexpr uint64_t combination(uint64_t n, uint64_t r)noexcept
	{
		return permutation(n, r) / factorial(r);
	}
}