template <typename OutputStream>
void
writeTo (const Host::T & host, OutputStream && output_stream)
{
	std::visit (
	    [&output_stream](auto && host) {
		    host.writeTo (std::forward<OutputStream> (output_stream));
	    },
	    host);
}
