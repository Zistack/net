template <typename Request,
    typename Response,
    typename Interface,
    typename... Arguments>
std::unique_ptr<Connection::Protocol::T<Request, Response, Interface>>
T<Request, Response, Interface, Arguments...>::make ()
{
	return std::apply (
	    std::make_unique<Connection::Protocol::T<Request, Response, Interface>,
	        Arguments...>,
	    this->arguments);
}
