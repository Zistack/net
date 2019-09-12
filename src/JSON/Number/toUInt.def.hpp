uint64_t
T::toUInt () const
{
	if
	(
		this -> m_mantissa ||
		(this -> m_exponent && (* this -> m_exponent) [0] == '-')
	)
	{
		throw Failure::SemanticError::T ("Number must be an integer\n");
	}

	if (this -> m_base [0] == '-')
	{
		throw Failure::SemanticError::T ("Number must be positive\n");
	}

	if (this -> m_exponent)
	{
		uint64_t exponent =
			IO::Util::toUInt (* this -> m_exponent);

		std::string base = this -> m_base;

		base . append (exponent, '0');

		return IO::Util::toUInt (base);
	}

	return IO::Util::toUInt (this -> m_base);
}
