template <typename Request, typename Response, typename Details>
struct T : Implementation::T <Request, Response, Details>
{
	using Implementation::T <Request, Response, Details>::T;

private:

	using Output::T <T, Response, Details>::output;

	friend Input::T <T, Request, Response, Details>;
	friend Output::T <T, Response, Details>;
};

