struct T
{
	T (const URI::T & uri);

	~T () = default;

	std::string client_key_base64;
	HTTP::Request::T request;

private:

	HTTP::Request::T
	createUpgradeRequest (const URI::T & uri);
};
