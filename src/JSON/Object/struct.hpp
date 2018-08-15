struct T : Value::T
{
	T (InputStream::T * json_input_stream);
	T (std::unordered_map<std::string, Value::T *> members);

	Value::T *
	at (std::string name);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	T *
	asObject () override;

	~T () override;

	std::unordered_map<std::string, Value::T *> members;
};
