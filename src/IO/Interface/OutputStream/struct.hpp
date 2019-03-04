struct T
{
	virtual void
	put (char c) = 0;

	void
	print (const std::string & message);

	virtual void
	write (const char * buffer, size_t count) = 0;
};
