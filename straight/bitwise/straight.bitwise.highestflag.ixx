export module straight.bitwise.highestflag;

export import straight.basic;

export namespace flower::straight
{
	constexpr bitarr8_t highestFlag(bitarr8_t n)noexcept
	{
		n = (n & 0xf0U) ? (n & 0xf0U) : n;
		n = (n & 0xccU) ? (n & 0xccU) : n;
		n = (n & 0xaaU) ? (n & 0xaaU) : n;
		return n;
	}

	constexpr bitarr16_t highestFlag(bitarr16_t n)noexcept
	{
		n = (n & 0xff00U) ? (n & 0xff00U) : n;
		n = (n & 0xf0f0U) ? (n & 0xf0f0U) : n;
		n = (n & 0xccccU) ? (n & 0xccccU) : n;
		n = (n & 0xaaaaU) ? (n & 0xaaaaU) : n;
		return n;
	}

	constexpr bitarr32_t highestFlag(bitarr32_t n)noexcept
	{
		n = (n & 0xffff0000UL) ? (n & 0xffff0000UL) : n;
		n = (n & 0xff00ff00UL) ? (n & 0xff00ff00UL) : n;
		n = (n & 0xf0f0f0f0UL) ? (n & 0xf0f0f0f0UL) : n;
		n = (n & 0xccccccccUL) ? (n & 0xccccccccUL) : n;
		n = (n & 0xaaaaaaaaUL) ? (n & 0xaaaaaaaaUL) : n;
		return n;
	}

	constexpr bitarr64_t highestFlag(bitarr64_t n)noexcept
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