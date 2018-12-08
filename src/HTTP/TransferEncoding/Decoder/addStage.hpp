void
T::addStage (const Specification::T & specification)
{
	throw Failure::Error::T ("Transfer Encoding '" + specification.identifier +
	    "' is not supported for decoding\n");
}
