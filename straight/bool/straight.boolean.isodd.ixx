export module straight.boolean.isodd;

import straight.boolean.iseven;

export namespace flower::straight
{
	template <class IntegerType>
	constexpr bool isOdd(IntegerType x)noexcept
	{
		return !isEven(x);
	}
}