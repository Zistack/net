bool
base64Data (char c)
{
	return IO::Class::alphanum (c) || (c == '+') || (c == '/');
}
