std::string
normalize (std::string string)
{
	for (char & c : string) c = (char) std::tolower (c);

	return string;
}
