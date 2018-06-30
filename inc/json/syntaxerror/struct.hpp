struct T : public std::exception
{
	T (std::string found, std::string expected = "")
	{
		message = std::string ("Unexpected " + found);
		if (!expected.empty ()) message += ", expected " + expected;
		message += "\n";
	}

	~T () = default;

	const char *
	what () const noexcept
	{
		return message.data ();
	}

	std::string message;
};
