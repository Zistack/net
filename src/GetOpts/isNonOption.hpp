bool
isNonOption (char * arg)
{
	return arg && (arg[0] != '-');
}
