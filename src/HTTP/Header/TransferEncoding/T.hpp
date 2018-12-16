T::T (const std::string & field_value)
{
	IO::String::T transfer_encoding_streams (field_value);

	IO::Interface::PeekableInputStream::T & input_stream =
	    transfer_encoding_streams.peekableInputStream ();

	auto parseSpecification =
	    [](IO::Interface::PeekableInputStream::T & input_stream) {
		    return HTTP::TransferEncoding::Specification::T (input_stream);
	    };

	this->specifications = IO::Util::consume (input_stream,
	    Rule::getList<HTTP::TransferEncoding::Specification::T,
	        parseSpecification>);
}
