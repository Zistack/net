template <typename Interface, typename Request>
struct T : Output::T <T <Interface, Request>, Request>
{
	template <typename OutputStream>
	void
	writeRequest (const Request & request, OutputStream && output_stream);

private:

	const Interface &
	interface () const;

	Interface &
	interface ();
};
