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
protected:

	T () = default;

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;

	friend OutputInterface::T
	<
		Interface,
		T <Interface, Request, Response>,
		Response
	>;
};
