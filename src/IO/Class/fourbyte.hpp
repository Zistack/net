bool
fourByte (char c)
{
	return (c >= 0xF0) && (c < 0xF1);
}

bool
fourByte (char32_t c)
{
	return (c >= 0x10000) && (c < 0x110000);
}
