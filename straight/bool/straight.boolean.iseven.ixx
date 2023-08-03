export module straight.boolean.iseven;

export namespace flower::straight
{
	template <class IntegerType>
	constexpr bool isEven(IntegerType x)noexcept
	{
		return (x & 1) == 0;
	}
}