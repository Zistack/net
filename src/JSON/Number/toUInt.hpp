uint64_t
T::toUInt () const
{
	if (this->mantissa ||
	    (this->exponent && this->exponent.stdString ()[0] == '-'))
		throw Failure::SemanticError::T ("Number must be an integer\n");

	if (this->base[0] == '-')
		throw Failure::SemanticError::T ("Number must be positive\n");

	if (this->exponent)
	{
		uint64_t exponent = IO::Util::toUInt (this->exponent.stdString ());

		std::string base = this->base;

		base.append (exponent, '0');

		return IO::Util::toUInt (base);
	}

	return IO::Util::toUInt (this->base);
}
