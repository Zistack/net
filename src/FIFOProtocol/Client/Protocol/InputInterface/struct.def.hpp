template <typename Interface, typename Response>
struct T : Input::T <T <Interface, Response>, Response>
{
	template <typename InputStream>
	Response
	readResponse (InputStream && input_stream);

private:

	Interface &
	interface ();

	const Interface &
	interface () const;
};
