template
<
	typename Request,
	typename Response,
	typename Details,
	typename ... Arguments
>
T <Request, Response, Details, Arguments ...>::T (Arguments ... arguments)
:	m_arguments (std::forward <Arguments> (arguments) ...)
{
}
