struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	// We'll want a constructor that lets us set the contents to something
	// interesting.

	bool
	contains (const std::string & name) const;

	// This is the part I wonder about.  I don't know exactly what kind of
	// accessors are desired here.

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	std::unordered_map <std::string, std::unique_ptr <Value::T>> m_members;
};
