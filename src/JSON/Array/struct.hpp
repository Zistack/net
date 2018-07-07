struct T : Value::T
{
	T (InputStream::T * json_input_stream);
	T (std::vector<Value::T *> members);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	~T () override;

	std::vector<Value::T *> members;
};
