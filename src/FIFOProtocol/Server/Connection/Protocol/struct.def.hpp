template <typename Interface, typename Request, typename Response>
struct T
:	InputOutputInterface::T
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

private:

	using InputOutputInterface::
		T <Interface, T <Interface, Request, Response>, Request, Response>::
		readRequest;
	using InputOutputInterface::
		T <Interface, T <Interface, Request, Response>, Request, Response>::
		map;
	using InputOutputInterface::
		T <Interface, T <Interface, Request, Response>, Request, Response>::
		cancelOutput;
	using InputOutputInterface::
		T <Interface, T <Interface, Request, Response>, Request, Response>::
		pushOutput;

	using OutputInterface::
		T <Interface, T <Interface, Request, Response>, Response>::
		writeResponse;
	using OutputInterface::
		T <Interface, T <Interface, Request, Response>, Response>::
		cancelProtocol;
};
