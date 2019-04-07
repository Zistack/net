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

	InputStream input_stream;
	Stage & stage;
	OutputStream output_stream;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};
