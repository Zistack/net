bool
threeByte (char c)
{
	return (c >= 0xE0) && (c < 0xF0);
}

bool
threeByte (char32_t c)
{
	return (c >= 0x800) && (c < 0x10000);
}
