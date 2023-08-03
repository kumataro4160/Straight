export module straight.integer.sign;

export import straight.basic;

export namespace flower::straight
{
	constexpr int8_t sign(int64_t x)noexcept
	{
		return x > 0LL ? 1 : (x < 0LL ? -1 : 0);
	}
}