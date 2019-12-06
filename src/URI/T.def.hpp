template <typename InputStream, typename>
T::T (InputStream && input_stream)
{
	this -> init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & uri_string)
{
	IO::String::Reader::T input_stream (uri_string);
	this -> init (input_stream);
	IO::Util::expectEOF (input_stream);
}

T::T
(
	const std::optional <std::string> & scheme,
	const std::optional <Authority::T> & authority,
	const Path::T & path,
	const std::optional <std::string> & query,
	const std::optional <std::string> & fragment
)
:	scheme (scheme),
	authority (authority),
	path (path),
	query (query),
	fragment (fragment)
{
}
