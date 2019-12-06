template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
struct T
:	Input::T <T <Interface, Protocol, Request, Response>, Request, Response>,
	OutputInterface::T <Interface, Protocol, Response>
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

protected:

	T () = default;

	~T () = default;

private:

	using Input::
		T <T <Interface, Protocol, Request, Response>, Request, Response>::
		prime;
	using Input::
		T <T <Interface, Protocol, Request, Response>, Request, Response>::
		run;
	using Input::
		T <T <Interface, Protocol, Request, Response>, Request, Response>::
		cancel;

	const Interface &
	interface () const;

	Interface &
	interface ();
};
