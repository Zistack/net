struct T
{
	T (Headers * headers);

	~T ();

	std::string transfer_encoding;
	unsigned int content_length;
	std::unordered_map <std::string, std::string> encoding_options;
};
