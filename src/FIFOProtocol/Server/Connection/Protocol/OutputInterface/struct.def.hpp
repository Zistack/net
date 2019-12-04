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

	const Interface &
	interface () const;

	Interface &
	interface ();

	const Protocol &
	protocol () const;

	Protocol &
	protocol ();
};
