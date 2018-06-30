void
T::writeTo (IO::OutputStream::T * output_stream)
{
	output_stream -> print (method);
	output_stream -> put (' ');
	uri.writeTo (output_stream);
	output_stream -> put (' ');
	output_stream -> print (version);
	output_stream -> print ("\r\n");

	Message::putHeaders (output_stream, headers);

	output_stream -> print ("\r\n");

	if (! entity) return;

	entity -> reset ();

	off_t i;
	for (i = 0; i < entity->size (); ++ i)
	{
		output_stream -> put (entity -> get ());
	}
}
