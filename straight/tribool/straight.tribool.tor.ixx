﻿export module straight.tribool.tor;

import straight.basic;

export namespace flower::straight
{
	constexpr tribool operator||(tribool l, tribool r)noexcept
	{
		//return tribool(l.x & (l.x << 1) | r.x & (r.x << 1) | l.x & r.x & tribool::false_value | (l.x | r.x) & tribool::true_value);
		constexpr bitarr32_t magic = 0b11111111'11100100'11010101'11000100UL;
		return tribool(static_cast<tribool::tribool_t>((magic >> (((l.x << 2) | r.x) * 2)) & 0b11UL));
	}
}