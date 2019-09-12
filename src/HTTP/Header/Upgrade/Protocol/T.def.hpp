template <typename InputStream>
T::T (InputStream && input_stream)
{
	this -> name = Util::normalize
	(
		Rule::getToken (std::forward <InputStream> (input_stream))
	);

	if (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
	{
		input_stream . get ();
		this -> version = Util::normalize
		(
			Rule::getToken (std::forward <InputStream> (input_stream))
		);
	}
}

T::T (const std::string & name, const std::optional <std::string> & version)
:	name (name), version (version)
{
}
