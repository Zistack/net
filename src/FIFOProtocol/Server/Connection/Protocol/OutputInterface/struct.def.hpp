template <typename Interface, typename Protocol, typename Response>
struct T : Output::T <T <Interface, Protocol, Response>, Response>
{
	template <typename OutputStream>
	void
	writeResponse (const Response & response, OutputStream && output_stream);

	void
	cancelProtocol ();

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
