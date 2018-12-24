std::unique_ptr<Host::T>
T::getHost (IO::Interface::PeekableInputStream::T & input_stream)
{
	if (IO::Util::test (input_stream, '['))
	{
		return getIPLiteral (input_stream);
	}
	else if (IO::Util::test (input_stream, IO::Class::digit))
	{
		return std::make_unique<Authority::IPv4Address::T> (input_stream);
	}
	else if (IO::Util::test (input_stream, Class::rnchar) ||
	    IO::Util::test (input_stream, '%'))
	{
		return std::make_unique<Authority::RegisteredName::T> (input_stream);
	}
	else
	{
		throw Failure::SyntaxError::T ("Expected valid host\n");
	}
}
