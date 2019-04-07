void
T::addStage (const Header::TransferEncoding::Specification::T & specification)
{
	throw Failure::ImplementationError::T
	(
		"Transfer Encoding '" +
			specification.identifier +
			"' is not supported for encoding\n"
	);
}
