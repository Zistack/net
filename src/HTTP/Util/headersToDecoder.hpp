template <bool is_request>
void
headersToDecoder (const HeaderMap::T & headers,
    TransferEncoding::Decoder::T & decoder)
{
	if (headers.contains ("Transfer-Encoding"))
	{
		if (headers.contains ("Content-Length"))
		{
			throw Failure::SemanticError::T (
			    "Cannot specify both Transfer-Encoding and Content-Length "
			    "headers\n");
		}

		Header::TransferEncoding::T transfer_encoding (
		    headers.at ("Transfer-Encoding"));

		if (transfer_encoding.specifications.empty ())
		{
			throw Failure::SemanticError::T (
			    "Expected nonempty transfer encoding specification\n");
		}

		TransferEncoding::Specification::T last_specification =
		    transfer_encoding.specifications.back ();
		transfer_encoding.specifications.pop_back ();

		if (last_specification.identifier != "chunked")
		{
			if (is_request)
			{
				throw Failure::SemanticError::T (
				    "The last transfer encoding must be 'chunked'");
			}
			else
			{
				// Everything is fine, but we read until the connection is
				// closed.  This is how the pipeline works usually, so we don't
				// need to do anthing.
			}
		}

		decoder.addFirstStage (last_specification);

		for (auto rit = transfer_encoding.specifications.rbegin ();
		     rit != transfer_encoding.specifications.rend ();
		     ++rit)
		{
			TransferEncoding::Specification::T & specification = *rit;
			decoder.addStage (specification);
		}
	}
	else
	{
		if (headers.contains ("Content-Length"))
		{
			Header::ContentLength::T content_length (
			    headers.at ("Content-Length"));

			decoder.setBoundedIdentity (content_length);
		}
		else
		{
			decoder.setUnboundedIdentity ();
		}
	}
}
