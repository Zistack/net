struct T : SimpleClientInterface::T
{
	template
	<
		typename ... Arguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v <SimpleClientInterface::T, Arguments ...>
		>
	>
	T (Arguments && ... arguments);

	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	stop ();

	void
	cancel ();

	HTTP::Response::T
	makeRequest (HTTP::Request::T && request);

	void
	setActive ();

	void
	setInactive ();

	~T () = default;

private:

	std::mutex m_active_mutex;
	std::condition_variable m_active_condition_variable;
	bool running;
	bool active;
	bool primed;
};
