T::T () : absolute (true) {}

T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (const std::string & path_string)
{
	IO::Util::consume (path_string,
	    [this](IO::Interface::PeekableInputStream::T & input_stream) {
		    this->init (input_stream);
	    });
}

template <class Iterable, typename>
T::T (Iterable && iterable, bool absolute) :
    segments (iterable.begin (), iterable.end ()),
    absolute (absolute)
{
}
