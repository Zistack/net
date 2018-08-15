struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);
	T (std::string string);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	T *
	asString () override;

	~T () override = default;

	std::string value;
};
