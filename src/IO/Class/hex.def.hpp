bool
hex (char c)
{
	return
		digit (c) ||
		((c >= 'A') && (c <= 'F')) ||
		((c >= 'a') && (c <= 'f'));
}
