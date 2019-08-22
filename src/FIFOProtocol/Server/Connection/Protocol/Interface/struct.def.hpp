template <typename Request, typename Response, typename Details>
struct T : Implementation::T <Request, Response, Details>
{
	friend Input::T <T, Request, Response, Details>;
	friend Output::T <T, Response, Details>;
};

