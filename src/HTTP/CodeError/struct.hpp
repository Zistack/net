struct T : Failure::Exception::T
{
	T (std::string message) = delete;
	T (std::string code, std::string message);

	std::string code;
};
