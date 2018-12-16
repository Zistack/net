struct T
{
	virtual std::string
	toString () const = 0;

	virtual std::unique_ptr<T>
	clone () const = 0;
};
