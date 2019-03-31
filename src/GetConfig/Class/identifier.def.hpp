bool
identifier (char c)
{
	return IO::Class::alphanum (c) || c == '_' || c == '-';
}
