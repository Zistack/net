template <typename... MemberTypes>
struct T : MemberPack::T<MemberTypes...>
{
	using InterfaceType = T;

	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	template <typename OutputStream>
	static void
	printHelp (OutputStream && output_stream,
	    size_t columns,
	    size_t tabwidth,
	    size_t indentation);

	~T () = default;

	private:
	using Members = MemberPack::T<MemberTypes...>;
};
