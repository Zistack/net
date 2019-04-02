bool
schar (char c)
{
	return IO::Class::alphanum (c) || c == '+' || c == '-' || c == '.';
}
