struct T
{
	virtual std::unique_ptr<Interface::Protocol::T>
	make () = 0;
};
