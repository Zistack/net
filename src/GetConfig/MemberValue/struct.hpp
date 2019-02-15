struct T
{
	virtual std::unique_ptr<T>
	clone () const = 0;

	// using InterfaceType = ...;
};
