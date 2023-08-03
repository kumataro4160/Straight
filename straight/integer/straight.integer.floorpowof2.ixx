export module straight.integer.floorpowof2;

export import straight.basic;
import straight.bitwise.highestflag;

export namespace flower::straight
{
	constexpr uint8_t floorPowOf2(uint8_t n)noexcept
	{
		return highestFlag(n);
	}

	constexpr uint16_t floorPowOf2(uint16_t n)noexcept
	{
		return highestFlag(n);
	}

	constexpr uint32_t floorPowOf2(uint32_t n)noexcept
	{
		return highestFlag(n);
	}

	constexpr uint64_t floorPowOf2(uint64_t n)noexcept
	{
		return highestFlag(n);
	}
}