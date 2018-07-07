struct T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);

	Value::T *
	get ();

	~T () = default;

	IO::Interface::PeekableInputStream::T * input_stream;
};
