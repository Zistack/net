template <typename Request, typename Response, typename Details>
struct T : Implementation::T <Request, Response, Details>
{
	using Implementation::T <Request, Response, Details>::T;

private:

	using Input::T <T, Response, Details>::input;
	using Output::T <T, Response, Details>::output;

	friend Input::T <T, Response, Details>;
	friend Output::T <T, Request, Details>;
};
