struct T
{
	virtual void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream) = 0;

	virtual void
	writeTo (IO::Interface::OutputStream::T & output_stream) const = 0;

	// The following should be present in all implementing subclasses.

	// using ValueType = ...;

	// T (ValueType value);

	// ValueType get () const;

	// void set (ValueType value);
};
