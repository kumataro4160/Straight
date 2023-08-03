export module straight.integer.powofnagative1;

export import straight.basic;

export namespace flower::straight
{
	constexpr int8_t powOfNegative1(int64_t n)noexcept
	{
		return 1 - ((n & 1) << 1);
	}
}