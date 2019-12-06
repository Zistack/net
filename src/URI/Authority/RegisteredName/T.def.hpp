T::T () : m_registered_name ("localhost") {}

template <typename InputStream, typename>
T::T (InputStream && input_stream)
{
	this -> m_registered_name = Rule::getClassDecode
	(
		std::forward <InputStream> (input_stream),
		Class::rnchar
	);
}

T::T (const std::string & registered_name) : m_registered_name (registered_name)
{
}
