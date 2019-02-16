struct T
{
	// using InterfaceType = ...;

	// T (const InterfaceType & value);

	// T (IO::Interface::PeekableInputStream::T & input_stream);

	virtual std::unique_ptr<T>
	clone () const = 0;

	// const InterfaceType & get () const;

	// void writeTo (IO::Interface::OutputStream::T & output_stream, size_t
	// indentation) const;
};
