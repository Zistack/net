template <typename Interface, typename Response>
struct T : Input::T <T <Interface, Response>, Response>
{
	template <typename InputStream>
	Response
	readResponse (InputStream && input_stream);

protected:

	using Input::T <T <Interface, Response>, Response>::T;

	~T () = default;

private:

	using Input::T <T <Interface, Response>, Response>::prime;
	using Input::T <T <Interface, Response>, Response>::run;
	using Input::T <T <Interface, Response>, Response>::cancel;
	using Input::T <T <Interface, Response>, Response>::push;

	Interface &
	interface ();

	const Interface &
	interface () const;
};
