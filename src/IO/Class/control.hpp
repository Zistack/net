bool
control (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc < 32) || (uc == 127);
}

bool
control (char16_t c)
{
	return (c < 32) || (c == 127);
}

bool
control (char32_t c)
{
	return (c < 32) || (c == 127);
}
