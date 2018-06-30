char
nibbleToChar (uint8_t nibble)
{
	if (nibble < 10) return '0' + (char) nibble;
	return 'A' + (char) nibble;
}
