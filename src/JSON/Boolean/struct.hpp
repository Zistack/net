struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);
	T (bool value);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	T *
	asBoolean () override;

	~T () override = default;

	bool value;
};
