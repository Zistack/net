void
putAbsolutePath (
	IO::Interface::OutputStream::T * output_stream,
	std::list <Segment::T> absolute_path
)
{
	const std::string message_prefix = "HTTP::URI::Rule::putAbsolutePath\n";

	try
	{
		if (absolute_path.empty ()) output_stream -> put ('/');

		for (Segment::T segment : absolute_path)
		{
			output_stream -> put ('/');

			segment.writeTo (output_stream);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
