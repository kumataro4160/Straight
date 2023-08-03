export module straight.integer.countnumshifts;

export import straight.basic;

export namespace flower::straight
{
	constexpr uint8_t countNumShifts(bitarr8_t x)noexcept
	{
		uint8_t ret = 0;
		if(x & 0xf0U)
		{
			ret += 4;
		}
		if(x & 0xccU)
		{
			ret += 2;
		}
		if(x & 0xaaU)
		{
			++ret;
		}
		return ret;
	}

	constexpr uint8_t countNumShifts(bitarr16_t x)noexcept
	{
		uint8_t ret = 0;
		if(x & 0xff00U)
		{
			ret += 8;
		}
		if(x & 0xf0f0U)
		{
			ret += 4;
		}
		if(x & 0xccccU)
		{
			ret += 2;
		}
		if(x & 0xaaaaU)
		{
			++ret;
		}
		return ret;
	}

	constexpr uint8_t countNumShifts(bitarr32_t x)noexcept
	{
		uint8_t ret = 0;
		if(x & 0xffff0000UL)
		{
			ret += 16;
		}
		if(x & 0xff00ff00UL)
		{
			ret += 8;
		}
		if(x & 0xf0f0f0f0UL)
		{
			ret += 4;
		}
		if(x & 0xccccccccUL)
		{
			ret += 2;
		}
		if(x & 0xaaaaaaaaUL)
		{
			++ret;
		}
		return ret;
	}

	constexpr uint8_t countNumShifts(bitarr64_t x)noexcept
	{
		uint8_t ret = 0;
		if(x & 0xffffffff00000000ULL)
		{
			ret += 32;
		}
		if(x & 0xffff0000ffff0000ULL)
		{
			ret += 16;
		}
		if(x & 0xff00ff00ff00ff00ULL)
		{
			ret += 8;
		}
		if(x & 0xf0f0f0f0f0f0f0f0ULL)
		{
			ret += 4;
		}
		if(x & 0xccccccccccccccccULL)
		{
			ret += 2;
		}
		if(x & 0xaaaaaaaaaaaaaaaaULL)
		{
			++ret;
		}
		return ret;
	}
}