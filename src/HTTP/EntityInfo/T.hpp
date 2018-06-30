T::T (Headers * headers)
{
	const std::string message_prefix = "HTTP::EntityInfo::T\n";

	try
	{
		std::unordered_map::iterator header_it;

		if ((header_it = headers -> find ("Transfer-Encoding")) != headers -> end ())
		{
			IO::String::T string (header_it -> second ());
			std::list <std::string> encodings = Rules::getList (& string);

			if (encodings.size () > 1)
			{
				throw NotImplementedError::T (
					"Only identity and chunked transfer encodings are "
					"supported\n"
				);
			}

			if (encodings.size () < 1)
			{
				throw BadMessageError::T (
					"Transfer-Encoding header value cannot be empty\n"
				);
			}

			this -> transfer_encoding = encodings [0];

			if (this -> transfer_encoding != "identity" &&
				this -> transfer_encoding != "chunked")
			{
				throw NotImplementedError::T (
					"Only identity and chunked transfer encodings are "
					"supported\n"
				);
			}
		}
		else if (
			(header_it = headers -> find ("Content-Length")) !=
			headers -> end ()
		)
		{
			IO::String::T string (header_it -> second ());
			this -> content_length = Rules.getNum (string);
			if (! string.eof ())
			{
				throw BadMEssageError::T (
					"Content-Length header value should only be a single "
					"number\n"
				);
			}
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
