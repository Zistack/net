template <typename Interface, typename Request, typename Response>
struct T
:	InputInterface::T <Interface, Response>,
	Output::T <T <Interface, Request, Response>, Request, Response>
{
	template <typename OutputStream>
	void
	writeRequest (const Request & request, OutputStream && output_stream);

	void
	pushInput (const Thread::Delay::T <Response> & response_delay);

	void
	stopInput ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	writeActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	writeIdle ();

protected:

	using Output::T <T <Interface, Request, Response>, Request, Response>::T;

	~T () = default;

private:

	using Output::
		T <T <Interface, Request, Response>, Request, Response>::
		prime;
	using Output::T <T <Interface, Request, Response>, Request, Response>::run;
	using Output::T <T <Interface, Request, Response>, Request, Response>::stop;
	using Output::
		T <T <Interface, Request, Response>, Request, Response>::
		cancel;
	using Output::T <T <Interface, Request, Response>, Request, Response>::push;

	const Interface &
	interface () const;

	Interface &
	interface ();
};
