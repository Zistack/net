int64_t
T::toInt () const
{
	if
	(
		this -> mantissa ||
		(this -> exponent && this -> exponent . stdString () [0] == '-')
	)
	{
		throw Failure::SemanticError::T ("Number must be ingeter\n");
	}

	if (this -> exponent)
	{
		uint64_t exponent = IO::Util::toUInt (this -> exponent . stdString ());

		std::string base = this -> base;

		base . append (exponent, '0');

		return IO::Util::toInt (base);
	}

	return IO::Util::toInt (this -> base);
}
