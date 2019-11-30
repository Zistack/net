template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
struct T
:	Input::T <T <Interface, Protocol, Request, Response>, Request, Response>,
	protected OutputInterface::T <Interface, Protocol, Response>
{
	template <typename InputStream>
	Request
	readRequest (InputStream && input_stream);

	Response
	map (const Request & request);

	void
	cancelOutput ();

	void
	pushOutput (const Thread::Delay::T <Response> & response_delay);

private:

	const Interface &
	interface () const;

	Interface &
	interface ();
};
