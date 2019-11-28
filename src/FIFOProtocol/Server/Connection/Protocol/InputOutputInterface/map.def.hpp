template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
Response
T <Interface, Protocol, Request, Response>::map (const Request & request)
{
	return this -> interface () . map (request);
}
