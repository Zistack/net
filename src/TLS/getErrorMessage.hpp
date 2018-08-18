std::string
getErrorMessage ()
{
	std::string error_message;

	unsigned long error_code;

	while ((error_code = ERR_get_error ()))
	{
		error_message += std::string (ERR_lib_error_string (error_code)) +
		    "::" + ERR_func_error_string (error_code) + ": " +
		    ERR_reason_error_string (error_code) + "\n";
	}

	return error_message;
}
