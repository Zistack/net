struct T
{
	using InterfaceType = uint64_t;

	T (const InterfaceType & value);

	template <typename InputStream>
	T (InputStream && input_stream);

	const InterfaceType &
	get () const;

	void
	set (const InterfaceType & value);

	void
	set (InterfaceType && value);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	~T () = default;

private:

	InterfaceType value;
};
