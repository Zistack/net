template <typename InputStream, typename Stage, typename OutputStream>
struct T
{
	T (InputStream input_stream, Stage & stage, OutputStream output_stream);

	void
	run ();

	void
	cancel ();

	~T () = default;

private:

	InputStream m_input_stream;
	Stage & m_stage;
	OutputStream m_output_stream;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};
