export module straight.boolean.isindetermine;

export import straight.basic;

export namespace flower::straight
{
	constexpr bool isIndetermine(tribool x)noexcept
	{
		return x.x == tribool::indetermine_value;
	}
}