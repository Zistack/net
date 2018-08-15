struct T
{
	virtual void
	writeTo (OutputStream::T * json_output_stream) = 0;

	virtual Array::T *
	asArray ();

	virtual Boolean::T *
	asBoolean ();

	virtual Number::T *
	asNumber ();

	virtual Object::T *
	asObject ();

	virtual String::T *
	asString ();

	virtual ~T ();
};
