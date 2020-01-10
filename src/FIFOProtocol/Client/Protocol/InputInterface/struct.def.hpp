template <typename Interface, typename Response>
struct T : Input::T <T <Interface, Response>, Response>
{
	template <typename InputStream>
	Response
	readResponse (InputStream && input_stream);

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	queueActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	queueIdle ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	readActive ();

	template
	<
		typename ProxyInterface = Interface,
		typename = std::enable_if_t <HooksLoadEvents::T <ProxyInterface>::value>
	>
	void
	readIdle ();

protected:

	using Input::T <T <Interface, Response>, Response>::T;

	~T () = default;

private:

	using Input::T <T <Interface, Response>, Response>::prime;
	using Input::T <T <Interface, Response>, Response>::run;
	using Input::T <T <Interface, Response>, Response>::stop;
	using Input::T <T <Interface, Response>, Response>::cancel;
	using Input::T <T <Interface, Response>, Response>::push;

	Interface &
	interface ();

	const Interface &
	interface () const;
};
