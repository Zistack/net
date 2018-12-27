T::T () :
    transfer_encoding (DEFAULT_TRANSFER_ENCODING),
    chunk_size (DEFAULT_CHUNK_SIZE)
{
}

T::T (JSON::Value::T * config_value) : T ()
{
	if (!config_value) return;

	JSON::Object::T & config_object = config_value->asObject ();

	JSON::Value::T * transfer_encoding_value =
	    config_object.at ("Transfer Encoding");

	if (transfer_encoding_value)
		this->transfer_encoding = transfer_encoding_value->asString ();

	JSON::Value::T * chunk_size_value = config_object.at ("Chunk Size");

	if (chunk_size_value)
		this->chunk_size = chunk_size_value->asNumber ().toUInt ();
}
