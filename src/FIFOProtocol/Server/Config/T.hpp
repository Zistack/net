T::T () :
    input_timeout (DEFAULT_INPUT_TIMEOUT),
    output_timeout (DEFAULT_OUTPUT_TIMEOUT)
{
}

T::T (JSON::Value::T * config_value) : T ()
{
	if (!config_value) return;

	JSON::Object::T & config_object = config_value->asObject ();

	JSON::Value::T * input_timeout_value = config_object.at ("Input Timeout");

	if (input_timeout_value)
		this->input_timeout = std::chrono::milliseconds (
		    input_timeout_value->asNumber ().toUInt ());

	JSON::Value::T * output_timeout_value = config_object.at ("Output Timeout");

	if (output_timeout_value)
		this->output_timeout = std::chrono::milliseconds (
		    output_timeout_value->asNumber ().toUInt ());
}