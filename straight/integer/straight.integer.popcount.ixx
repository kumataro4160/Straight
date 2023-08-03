export module straight.integer.popcount;

export import straight.basic;

export namespace flower::straight
{
	constexpr uint8_t popcount(bitarr8_t x)noexcept
	{
		x = ((x & 0xaa) >> 1) + (x & 0x55);
		x = ((x & 0xcc) >> 2) + (x & 0x33);
		x = ((x & 0xf0) >> 4) + (x & 0x0f);
		return x;
	}

	constexpr uint8_t popcount(bitarr16_t x)noexcept
	{
		x = ((x & 0xaaaa) >> 1) + (x & 0x5555);
		x = ((x & 0xcccc) >> 2) + (x & 0x3333);
		x = ((x & 0xf0f0) >> 4) + (x & 0x0f0f);
		x = ((x & 0xff00) >> 8) + (x & 0x00ff);
		return static_cast<uint8_t>(x);
	}

	constexpr uint8_t popcount(bitarr32_t x)noexcept
	{
		x = ((x & 0xaaaaaaaaUL) >> 1) + (x & 0x55555555UL);
		x = ((x & 0xccccccccUL) >> 2) + (x & 0x33333333UL);
		x = ((x & 0xf0f0f0f0UL) >> 4) + (x & 0x0f0f0f0fUL);
		x = ((x & 0xff00ff00UL) >> 8) + (x & 0x00ff00ffUL);
		x = ((x & 0xffff0000UL) >> 16) + (x & 0x0000ffffUL);
		return static_cast<uint8_t>(x);
	}

	constexpr uint8_t popcount(bitarr64_t x)noexcept
	{
		x = ((x & 0xaaaaaaaaaaaaaaaaULL) >> 1) + (x & 0x5555555555555555ULL);
		x = ((x & 0xccccccccccccccccULL) >> 2) + (x & 0x3333333333333333ULL);
		x = ((x & 0xf0f0f0f0f0f0f0f0ULL) >> 4) + (x & 0x0f0f0f0f0f0f0f0fULL);
		x = ((x & 0xff00ff00ff00ff00ULL) >> 8) + (x & 0x00ff00ff00ff00ffULL);
		x = ((x & 0xffff0000ffff0000ULL) >> 16) + (x & 0x0000ffff0000ffffULL);
		x = ((x & 0xffffffff00000000ULL) >> 32) + (x & 0x00000000ffffffffULL);
		return static_cast<uint8_t>(x);
	}
}