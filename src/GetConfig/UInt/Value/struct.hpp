struct T : Member::ValueImpl::T<T>
{
	using InterfaceType = uint64_t;

	T (const InterfaceType & value);

	T (IO::Interface::PeekableInputStream::T & input_stream);

	void
	validate () const;

	const InterfaceType &
	get () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const;

	~T () = default;

	private:
	uint64_t value;
};
