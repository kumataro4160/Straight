export module straight.boolean.istrue;

export import straight.basic;

export namespace flower::straight
{
	constexpr bool isTrue(tribool x)noexcept
	{
		return x.x == tribool::true_value;
	}
}