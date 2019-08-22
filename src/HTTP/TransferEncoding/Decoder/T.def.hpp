T::T ()
{
	this -> addUnboundedIdentity ();
}

T::T (uint64_t content_length)
{
	this -> addBoundedIdentity (content_length);
}

T::T (const NullableString::T & transfer_encoding_string, bool is_request)
{
	Header::TransferEncoding::T transfer_encoding
	(
		transfer_encoding_string . stdString ()
	);

	if (transfer_encoding . m_specifications . empty ())
	{
		throw Failure::SemanticError::T
		(
			"Expected nonempty transfer encoding specification\n"
		);
	}

	Header::TransferEncoding::Specification::T last_specification =
		transfer_encoding . m_specifications . back ();
	transfer_encoding . m_specifications . pop_back ();

	if (last_specification . m_identifier != "chunked")
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

	auto rit = transfer_encoding . m_specifications . rbegin ();
	for (; rit != transfer_encoding . m_specifications . rend (); ++ rit)
	{
		Header::TransferEncoding::Specification::T & specification = * rit;
		this -> addStage (specification);
	}
}
