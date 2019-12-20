template <typename Interface>
size_t
T <Interface>::outputBufferSize (size_t config_max_buffer_size)
{
	size_t negotiated_max_buffer_size =
		gnutls_record_get_max_size (this -> interface () . session) -
		gnutls_record_overhead_size (this -> interface () . session);

	return negotiated_max_buffer_size < config_max_buffer_size ?
		negotiated_max_buffer_size :
		config_max_buffer_size;
}
