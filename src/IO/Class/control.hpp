bool
control (char c)
{
	return (c < 32) || (c == 127);
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
