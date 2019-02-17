struct T : Member::ValueImpl::T<T>
{
	using InterfaceType = std::string;

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
	std::string value;
};
