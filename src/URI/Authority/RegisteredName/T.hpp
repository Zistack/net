T::T () : registered_name ("localhost") {}

template <typename InputStream>
T::T (InputStream && input_stream)
{
	this->registered_name = Rule::getClassDecode (
	    std::forward<InputStream> (input_stream), Class::rnchar);
}

T::T (const std::string & registered_name) : registered_name (registered_name)
{
}
