struct T
{
	virtual void
	writeTo (IO::Interface::OutputStream::T * output_stream,
	    size_t indentation = 0) = 0;

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

	virtual ~T () = default;
};
