struct T
{
	T (IO::Interface::InputStream::T <char> * input_stream);

	void
	put (Response::T * response);

	Response::T *
	get ();

	~T () = default;

	IO::Interface::InputStream::T <char> * input_stream;
	bool complete;
	Response::T * response;

	std::shared_mutex mutex;
	std::condition_variable_any condition_variable;
};
