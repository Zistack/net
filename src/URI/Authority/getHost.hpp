template <typename InputStream>
Host::T
T::getHost (InputStream && input_stream)
{
	if (IO::Util::test (std::forward<InputStream> (input_stream), '['))
	{
		return getIPLiteral (std::forward<InputStream> (input_stream));
	}
	else if (IO::Util::test (
	             std::forward<InputStream> (input_stream), IO::Class::digit))
	{
		return Authority::IPv4Address::T (
		    std::forward<InputStream> (input_stream));
	}
	else if (IO::Util::test (
	             std::forward<InputStream> (input_stream), Class::rnchar) ||
	    IO::Util::test (std::forward<InputStream> (input_stream), '%'))
	{
		return Authority::RegisteredName::T (
		    std::forward<InputStream> (input_stream));
	}
	else
	{
		throw Failure::SyntaxError::T ("Expected valid host\n");
	}
}
