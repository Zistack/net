void
T::init (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string first_part = getFirstPart (input_stream);

	if (IO::Util::test (input_stream, '@'))
	{
		input_stream.get ();

		this->user_info = IO::Util::consume (first_part, getUserInfo);

		this->initHostAndPort (input_stream);
	}
	else
	{
		IO::Util::consume (first_part,
		    [this](IO::Interface::PeekableInputStream::T & input_stream) {
			    this->initHostAndPort (input_stream);
		    });
	}
}
