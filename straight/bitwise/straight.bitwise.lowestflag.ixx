export module straight.bitwise.lowestflag;

export import straight.basic;

export namespace flower::straight
{
	constexpr bitarr8_t lowestflag(bitarr8_t n)noexcept
	{
		return n & static_cast<bitarr8_t>(-static_cast<int8_t>(n));
	}

	constexpr bitarr16_t lowestflag(bitarr16_t n)noexcept
	{
		return n & static_cast<bitarr16_t>(-static_cast<int16_t>(n));
	}

	constexpr bitarr32_t lowestflag(bitarr32_t n)noexcept
	{
		return n & static_cast<bitarr32_t>(-static_cast<int32_t>(n));
	}

	constexpr bitarr64_t lowestflag(bitarr64_t n)noexcept
	{
		return n & static_cast<bitarr64_t>(-static_cast<int64_t>(n));
	}
}