template <typename Request, typename Response, typename Interface>
T<Request, Response, Interface>::T (Interface & interface,
    Output::T<Response, Interface> & output) :
    interface (interface),
    output (output)
{
}
