bool
uric (char c)
{
	return reserved (c) || unreserved (c);
}
