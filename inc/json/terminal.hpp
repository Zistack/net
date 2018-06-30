bool
terminal (std::char_traits<char>::int_type c)
{
	return eof (c) || whitespace (c) || closer (c);
}
