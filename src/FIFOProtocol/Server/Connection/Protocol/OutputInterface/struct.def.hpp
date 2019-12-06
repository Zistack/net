template <typename Interface, typename Protocol, typename Response>
struct T : Output::T <T <Interface, Protocol, Response>, Response>
{
	template <typename OutputStream>
	void
	writeResponse (const Response & response, OutputStream && output_stream);

	void
	cancelProtocol ();

protected:

	using Output::T <T <Interface, Protocol, Response>, Response>::T;

	~T () = default;

private:

	using Output::T <T <Interface, Protocol, Response>, Response>::prime;
	using Output::T <T <Interface, Protocol, Response>, Response>::run;
	using Output::T <T <Interface, Protocol, Response>, Response>::cancel;
	using Output::T <T <Interface, Protocol, Response>, Response>::push;

	const Interface &
	interface () const;

	Interface &
	interface ();

	const Protocol &
	protocol () const;

	Protocol &
	protocol ();
};
