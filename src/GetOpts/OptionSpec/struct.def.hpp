struct T
{
	T
	(
		char short_form,
		std::function <void (void)> flagAction,
		std::string description = ""
	);

	T
	(
		char short_form,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	T
	(
		char short_form,
		std::function <void (void)> flagAction,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	T
	(
		std::string long_form,
		std::function <void (void)> flagAction,
		std::string description = ""
	);

	T
	(
		std::string long_form,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	T
	(
		std::string long_form,
		std::function <void (void)> flagAction,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	T
	(
		char short_form,
		std::string long_form,
		std::function <void (void)> flagAction,
		std::string description = ""
	);

	T
	(
		char short_form,
		std::string long_form,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	T
	(
		char short_form,
		std::string long_form,
		std::function <void (void)> flagAction,
		std::function <void (char *)> argaction,
		std::string description = ""
	);

	int
	compare (const T & other) const;

	bool
	operator < (const T & other) const
	{
		return this -> compare (other) < 0;
	}

	bool
	operator > (const T & other) const
	{
		return this -> compare (other) > 0;
	}

	bool
	operator == (const T & other) const
	{
		return this -> compare (other) == 0;
	}

	bool
	operator != (const T & other) const
	{
		return this -> compare (other) != 0;
	}

	bool
	operator <= (const T & other) const
	{
		return this -> compare (other) <= 0;
	}

	bool
	operator >= (const T & other) const
	{
		return this -> compare (other) >= 0;
	}

	bool
	requiresArgument () const;

	bool
	takesArgument () const;

	std::string
	name () const;

	~T () = default;

	char short_form;
	std::string long_form;

	std::function <void (void)> flagAction;
	std::function <void (char *)> argAction;

	std::string description;
};
