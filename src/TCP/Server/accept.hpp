Client::T *
T::accept ()
{
	return new Client::T (this);
}
