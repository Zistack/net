template
<
	typename Request,
	typename Response,
	typename Interface,
	typename ... Arguments
>
T <Request, Response, Interface, Arguments ...>::T (Arguments ... arguments)
:	arguments (std::forward <Arguments> (arguments) ...)
{
}
