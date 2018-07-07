void
T::writeTo (OutputStream::T * json_output_stream)
{
	const std::string message_prefix = "JSON::String::writeTo\n";

	try
	{
		json_output_stream->put ('"');

		for (char c : this->value)
		{
			switch (c)
			{
			case '"':
				json_output_stream->print ("\\\"");
				break;
			case '\\':
				json_output_stream->print ("\\\\");
				break;
			case '\x08':
				json_output_stream->print ("\\b");
				break;
			case '\x09':
				json_output_stream->print ("\\t");
				break;
			case '\x0A':
				json_output_stream->print ("\\n");
				break;
			case '\x0C':
				json_output_stream->print ("\\f");
				break;
			case '\x0D':
				json_output_stream->print ("\\r");
				break;
			default:
				if (Class::control (c))
					Rule::putEscape (json_output_stream, (char32_t) c);
				else
					json_output_stream->put (c);
			}
		}

		json_output_stream->put ('"');
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
