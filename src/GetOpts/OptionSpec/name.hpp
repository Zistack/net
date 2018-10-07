std::string
T::name () const
{
	if (!this->long_form.empty ())
		return this->long_form;
	else
		return {this->short_form};
}
