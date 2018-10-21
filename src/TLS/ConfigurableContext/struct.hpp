struct T : virtual Context::T
{
	virtual ~T () = default;

	protected:
	T ();

	void
	configure (const Config::T & config);
};
