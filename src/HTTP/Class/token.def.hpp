bool
token (char c)
{
	return
		IO::Class::alphanum (c) ||
		c == '!' ||
		c == '#' ||
		c == '$' ||
		c == '%' ||
		c == '&' ||
		c == '\'' ||
		c == '*' ||
		c == '+' ||
		c == '-' ||
		c == '.' ||
		c == '^' ||
		c == '_' ||
		c == '`' ||
		c == '|' ||
		c == '~';
}
