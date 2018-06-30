struct T
{
	T ();

	void
	put (Response::T * response);

	Response::T *
	get ();

	~T () = default;

	bool complete;
	Response::T * response;

	std::shared_mutex mutex;
	std::condition_variable_any condition_variable;
};
