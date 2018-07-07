struct T
{
	virtual void
	writeTo (OutputStream::T * json_output_stream) = 0;

	virtual ~T ();
};
