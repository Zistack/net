void
init (T * number, std::string base)
{
	number->negative = false;
	number->base = new std::string (base);
	number->mantissa = NULL;
	number->exponent_negative = false;
	number->exponent = NULL;
}
