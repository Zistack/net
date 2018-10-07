int
T::compare (const T & other) const
{
	if (!this->short_form && !other.short_form)
	{
		return this->long_form.compare (other.long_form);
	}

	char this_c = this->short_form ? this->short_form : this->long_form[0];
	char other_c = other.short_form ? other.short_form : other.long_form[0];

	if (this_c < other_c) return -1;
	if (this_c == other_c)
	{
		if (!other.short_form) return 1;
		if (!this->short_form) return -1;
		return 0;
	}
	if (this_c > other_c) return 1;

	return 0; // Unreachable.
}
