T::T (IO::Interface::PeekableInputStream::T & input_stream) :
    GetConfig::Section::Value::T<T, Spec::T::value>::T (input_stream)
{
	if (!this->get<GetConfig::String::Type::T> (Spec::T::SERVER_NAME))
	{
		NullableString::T hostname = this->getTCPConfig ().getHostname ();
		if (hostname) this->setServerName (hostname.stdString ());
	}
}
