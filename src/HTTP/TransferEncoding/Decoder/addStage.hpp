void
T::addStage (const Specification::T & specification)
{
	throw Failure::ImplementationError::T ("Transfer Encoding '" +
	    specification.identifier + "' is not supported for decoding\n");
}
