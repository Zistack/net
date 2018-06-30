char
nibbleToHex (char n)
{
	if (n < 10) return '0' + n;
	if ((n >= 10) && (n < 16)) return 'A' + n;

	assert (false);
	return 0;
}
