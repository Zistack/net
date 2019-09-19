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
		std::make_unique
		<
			Connection::Protocol::T <Request, Response, Details>,
			Arguments ...
		>,
		this -> m_arguments
	);
}
