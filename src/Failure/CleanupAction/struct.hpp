struct T
{
	T (std::function<void(void)> f);

	~T ();

	std::function<void(void)> f;
};
