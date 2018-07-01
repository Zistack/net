T::~T ()
{
	Throwable::T * exception = std::atomic_load (&this->exception);

	if (exception) delete exception;
}
