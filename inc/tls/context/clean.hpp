void
clean (T * context)
{
	SSL_CTX_free (context->ssl_ctx);
}
