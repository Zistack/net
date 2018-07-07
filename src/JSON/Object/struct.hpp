struct T : Value::T
{
	T (InputStream::T * json_input_stream);
	T (std::unordered_map<std::string, Value::T *> members);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	~T () override;

	std::unordered_map<std::string, Value::T *> members;
};
