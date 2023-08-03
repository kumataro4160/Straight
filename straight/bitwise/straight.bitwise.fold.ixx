export module straight.bitwise.fold;

export import straight.basic;

export namespace flower::straight
{
	constexpr bitarr8_t fold(bitarr8_t x, uint8_t n)noexcept
	{
		if(n == 0)
		{
			return 0U;
		}
		bitarr8_t ret = x;
		for(uint8_t i = 8U / n; i; --i)
		{
			ret |= x >> n;
		}
		return ret & ((1U << n) - 1);
	}

	constexpr bitarr16_t fold(bitarr16_t x, uint8_t n)noexcept
	{
		if(n == 0)
		{
			return 0U;
		}
		bitarr16_t ret = x;
		for(uint8_t i = 16U / n; i; --i)
		{
			ret |= x >> n;
		}
		return ret & ((1U << n) - 1);
	}

	constexpr bitarr32_t fold(bitarr32_t x, uint8_t n)noexcept
	{
		if(n == 0)
		{
			return 0UL;
		}
		bitarr32_t ret = x;
		for(uint8_t i = 32U / n; i; --i)
		{
			ret |= x >> n;
		}
		return ret & ((1UL << n) - 1);
	}

	constexpr bitarr64_t fold(bitarr64_t x, uint8_t n)noexcept
	{
		if(n == 0)
		{
			return 0ULL;
		}
		bitarr64_t ret = x;
		for(uint8_t i = 64U / n; i; --i)
		{
			ret |= x >> n;
		}
		return ret & ((1ULL << n) - 1);
	}
}