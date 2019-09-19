template
<
	typename Request,
	typename Response,
	typename Details,
	typename ... Arguments
>
std::unique_ptr <Connection::Protocol::T <Request, Response, Details>>
T <Request, Response, Details, Arguments ...>::make ()
{
	return std::apply
	(
		[] (Arguments ... arguments)
		{
			return std::make_unique
			<
				Connection::Protocol::T <Request, Response, Details>
			>
			(
				std::forward <Arguments> (arguments) ...
			);
		},
		this -> m_arguments
	);
}
