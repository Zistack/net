bool
supplementaryPlane (char32_t c)
{
	return (c >= 0x10000) && (c < 0x110000);
}
