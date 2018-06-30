bool
continuation (char c)
{
	return (c >= 0x80) && (c < 0xC0);
}
