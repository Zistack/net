template <typename InputStream>
T::T (InputStream && input_stream)
{
	this -> m_name = Rule::getToken (std::forward <InputStream> (input_stream));

	if (IO::Util::test (std::forward <InputStream> (input_stream), '/'))
	{
		input_stream . get ();
		this -> m_version =
			Rule::getToken (std::forward <InputStream> (input_stream));
	}
}

T::T (const std::string & name, const NullableString::T & version)
:	m_name (name), m_version (version)
{
}
