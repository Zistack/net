bool
basicMultilingualPlane (char16_t c)
{
	return (c < 0xD800) || (c >= 0xE000);
}

bool
basicMultilingualPlane (char32_t c)
{
	return (c < 0xD800) || ((c >= 0xE000) && (c < 0x10000));
}
