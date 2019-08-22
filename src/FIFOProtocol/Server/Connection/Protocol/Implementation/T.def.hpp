template <typename Request, typename Response, typename Details>
template <typename ... Arguments>
T <Request, Response, Details>::T (Arguments && ... arguments)
:	m_details (std::forward <Arguments> (arguments) ...)
{
}
