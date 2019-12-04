template <typename Writable>
std::string
toString (Writable && writable)
{
	std::string string;
	String::Writer::T output_stream (string);
	writable . writeTo (output_stream);

	return string;
}
