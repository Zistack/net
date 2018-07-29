struct T
{
	virtual void
	put (char c) = 0;

	void
	print (std::string message);

	virtual void
	write (char * buffer, size_t count) = 0;
};
