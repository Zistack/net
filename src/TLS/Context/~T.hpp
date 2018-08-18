T::~T ()
{
	SSL_CTX_free (this->ssl_ctx);
}
