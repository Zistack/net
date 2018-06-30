void
clean (T * number)
{
	if (number->base) delete number->base;
	if (number->mantissa) delete number->mantissa;
	if (number->exponent) delete number->exponent;
}
