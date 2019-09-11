int64_t
T::toInt () const
{
	if
	(
		this -> m_mantissa ||
		(this -> m_exponent && this -> m_exponent . stdString () [0] == '-')
	)
	{
		throw Failure::SemanticError::T ("Number must be ingeter\n");
	}

	if (this -> m_exponent)
	{
		uint64_t exponent =
			IO::Util::toUInt (this -> m_exponent . stdString ());

		std::string base = this -> m_base;

		base . append (exponent, '0');

		return IO::Util::toInt (base);
	}

	return IO::Util::toInt (this -> m_base);
}
