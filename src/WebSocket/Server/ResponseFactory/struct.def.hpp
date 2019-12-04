template <bool upgrade_required>
struct T
{
	T (const HTTP::Request::T & request);

	~T () = default;

	HTTP::Response::T response;

private:

	HTTP::Response::T
	createUpgradeResponse (const HTTP::Request::T & request);
};
