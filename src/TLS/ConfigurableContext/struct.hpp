struct T : virtual Context::T
{
	T ();

	virtual ~T () = default;

	protected:
	void
	configure (const Config::T & config);
};
