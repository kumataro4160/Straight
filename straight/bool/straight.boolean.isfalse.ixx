export module straight.boolean.isfalse;

export import straight.basic;

export namespace flower::straight
{
	constexpr bool isFalse(tribool x)noexcept
	{
		return x.x == tribool::false_value;
	}
}