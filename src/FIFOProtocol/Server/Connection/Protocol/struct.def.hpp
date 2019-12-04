template <typename Interface, typename Request, typename Response>
struct T
:	private InputOutputInterface::T
	<
		Interface,
		T <Interface, Request, Response>,
		Request,
		Response
	>
{
	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

protected:

	T () = default;

	const T &
	fifoProtocol () const;

	T &
	fifoProtocol ();

	~T () = default;
};
