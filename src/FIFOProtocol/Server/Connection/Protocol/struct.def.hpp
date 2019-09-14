template <typename Request, typename Response, typename Details>
struct T
:	private Input::T
	<
		T <Request, Response, Details>,
		Request,
		Response,
		Details
	>,
	private Output::T
	<
		T <Request, Response, Details>,
		Response,
		Details
	>
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

	// Internal members

	Details m_details;

private:

	// Submodules

	friend Input::T <T, Request, Response, Details>;
	friend Output::T <T, Response, Details>;
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
