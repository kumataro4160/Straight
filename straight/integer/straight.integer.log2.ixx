export module straight.integer.log2;

export import straight.basic;
import straight.integer.floorpowof2;
import straight.integer.countnumshifts;

export namespace flower::straight
{
	constexpr uint8_t log2(uint8_t x)noexcept
	{
		return countNumShifts(floorPowOf2(x));
	}

	constexpr uint8_t log2(uint16_t x)noexcept
	{
		return countNumShifts(floorPowOf2(x));
	}

	constexpr uint8_t log2(uint32_t x)noexcept
	{
		return countNumShifts(floorPowOf2(x));
	}

	constexpr uint8_t log2(uint64_t x)noexcept
	{
		return countNumShifts(floorPowOf2(x));
	}
}