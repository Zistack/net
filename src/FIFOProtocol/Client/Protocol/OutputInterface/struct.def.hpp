template <typename Interface, typename Request>
struct T : Output::T <T <Interface, Request>, Request>
{
	template <typename OutputStream>
	void
	writeRequest (const Request & request, OutputStream && output_stream);

protected:

	using Output::T <T <Interface, Request>, Request>::T;

	~T () = default;

private:

	using Output::T <T <Interface, Request>, Request>::prime;
	using Output::T <T <Interface, Request>, Request>::run;
	using Output::T <T <Interface, Request>, Request>::cancel;
	using Output::T <T <Interface, Request>, Request>::push;

	const Interface &
	interface () const;

	Interface &
	interface ();
};
