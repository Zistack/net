struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	template <class Iterable>
	T (const Iterable & members);

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation = 0) override;

	T &
	asArray () override;

	~T () override = default;

	private:
	std::vector<std::unique_ptr<Value::T>> members;
};
