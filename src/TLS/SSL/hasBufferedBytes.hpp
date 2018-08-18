bool
T::hasBufferedBytes ()
{
	this->mutex.lock ();
	bool pending = (bool) SSL_pending (this->ssl);
	this->mutex.unlock ();

	return pending;
}
