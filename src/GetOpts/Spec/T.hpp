T::T (std::string usage_suffix,
    std::string description,
    std::initializer_list<OptionSpec::T> options) :
    usage_suffix (usage_suffix),
    description (description),
    options (options)
{
	for (const OptionSpec::T & option : this->options)
	{
		if (!option.long_form.empty ())
			this->long_map.insert ({option.long_form, option});
		if (option.short_form)
			this->short_map.insert ({option.short_form, option});
	}
}
