T::~T ()
{
	delete base;
	if (mantissa) delete mantissa;
	if (exponent) delete exponent;
}
