template <typename Request, typename Response, typename Details>
struct T
:	Input::T
	<
		Interface::T <Request, Response, Details>,
		Request,
		Response,
		Details
	>,
	Output::T <Interface::T <Request, Response, Details>, Response, Details>
{
	template <typename... Arguments>
	T (Arguments && ... arguments);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	cancel ();

	~T () = default;

protected:

	const Details &
	details () const;

	Details &
	details ();

private:

	// Internal members

	Details m_details;
};

static_assert
(
	IO::
		TypeTraits::
		IsProtocol::
		T
		<
			T
			<
				std::monostate,
				std::monostate,
				TypeTraits::ServerDetails::T <std::monostate, std::monostate>
			>
		>::
		value
);
