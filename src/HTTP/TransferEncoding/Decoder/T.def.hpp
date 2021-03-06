T::T ()
{
	this -> addUnboundedIdentity ();
}

T::T (uint64_t content_length)
{
	this -> addBoundedIdentity (content_length);
}

T::T
(
	const std::optional <std::string> & transfer_encoding_string,
	bool is_request
)
{
	Header::TransferEncoding::T transfer_encoding (* transfer_encoding_string);

	if (transfer_encoding . specifications . empty ())
	{
		throw Failure::SemanticError::T
		(
			"Expected nonempty transfer encoding specification\n"
		);
	}

	Header::TransferEncoding::Specification::T last_specification =
		transfer_encoding . specifications . back ();
	transfer_encoding . specifications . pop_back ();

	if (last_specification . identifier != "chunked")
	{
		if (is_request)
		{
			throw Failure::SemanticError::T
			(
				"The last transfer encoding must be 'chunked'"
			);
		}
		else
		{
			// Everything is fine, but we will read until the connection is 
			// closed.  This is how the pipeline works usually, do we don't need 
			// to do anything.
		}
	}

	this -> addFirstStage (last_specification);

	auto rit = transfer_encoding . specifications . rbegin ();
	for (; rit != transfer_encoding . specifications . rend (); ++ rit)
	{
		Header::TransferEncoding::Specification::T & specification = * rit;
		this -> addStage (specification);
	}
}
