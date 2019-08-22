template <typename ... Recoders>
struct T
{
	template <typename ... Arguments>
	T (Arguments && ... arguments);

	template <typename InputStream, typename OutputStream>
	void
	recode (InputStream && input_stream, OutputStream && output_stream);

	~T () = default;

private:

	std::variant <Recoders ...> m_recoder;
};
