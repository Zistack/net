struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);

	template <class Iterable>
	T (const Iterable & members);

	Value::T *
	at (std::string name);

	void
	writeTo (IO::Interface::OutputStream::T * output_stream,
	    size_t indentation = 0) override;

	T *
	asObject () override;

	~T () override;

	std::unordered_map<std::string, Value::T *> members;
};
