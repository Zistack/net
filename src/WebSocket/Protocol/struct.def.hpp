template <typename Interface>
struct T : InputOutputInterface::T <Interface>
{
	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	using InputOutputInterface::T <Interface>::send;
	using InputOutputInterface::T <Interface>::ping;
	using InputOutputInterface::T <Interface>::pong;

protected:

	using InputOutputInterface::T <Interface>::T;

	~T () = default;
};
