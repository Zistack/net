void
chunked
(
	IO::Interface::PeekableInputStream <char> * filtered_input_stream,
	IO::Interface::PeekableInputStream <char> * input_stream,
	IO::OutputStream::T * output_stream
)
{
	const std::string message_prefix = "HTTP::TransferEncoding::Chunked\n";

	try
	{
		while (true)
		{
			uint64_t chunk_size = Rules::getHex (filtered_input_stream);

			while (IO::Util::test (filtered_input_stream, ';'))
			{
				IO::Util::expect (filtered_input_stream, ';');

				// We simply discard the results here, because we don't actually
				// understand any extensions.
				Rules::getChunkExtension (filtered_input_stream);
			}

			IO::Util::expect (filtered_input_stream, '\n');

			if (! chunk_size) break;

			identity (input_stream, output_stream, chunk_size);

			IO::Util::expect (filtered_input_stream, '\n');
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
