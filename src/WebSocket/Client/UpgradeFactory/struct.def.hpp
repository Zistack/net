struct T
{
	T ();

	HTTP::Request::T
	createUpgradeRequest (const URI::T & uri);

	~T () = default;

	std::string client_key_base64;
};
