export module straight.boolean.isnan;

export import straight.basic;

export namespace flower::straight
{
	constexpr bool isNaN(tribool x)noexcept
	{
		return x.x == tribool::nan;
	}
}