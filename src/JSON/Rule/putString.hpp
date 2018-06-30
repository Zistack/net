void
putString (IO::Interface::OutputStream::T <char> * output_stream, std::string value)
{
	const std::string message_prefix = "Failed to write string:\n";

	try
	{
		output_stream -> put ('"');

		for (char c : value)
		{
			switch (c)
			{
			case '"':
				output_stream -> print ("\\\"");
				break;
			case '\\':
				output_stream -> print ("\\\\");
				break;
			case '\x08':
				output_stream -> print ("\\b");
				break;
			case '\x09':
				output_stream -> print ("\\t");
				break;
			case '\x0A':
				output_stream -> print ("\\n");
				break;
			case '\x0C':
				output_stream -> print ("\\f");
				break;
			case '\x0D':
				output_stream -> print ("\\r");
				break;
			default:
				if (c < '\x20') Rule::putEscape (output_stream, c);
				else output_stream->put (c);
			}
		}

		output_stream->put ('"');
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
}
