struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	// I'll probably want a constructor that lets you set the initial contents
	// to something.  I'll figure that out with the accessors.

	// I feel like some accessors are appropriate here.

	// I think we want to iterate over this thing.

	// Indexed access?  IDK.

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	std::vector <std::unique_ptr <Value::T>> members;
};
