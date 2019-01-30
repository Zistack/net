struct T : Failure::Cancellable::T
{
	virtual void
	prime () = 0;

	virtual void
	run (NonblockingInputStream::T & input_stream,
	    NonblockingOutputStream::T & output_stream) = 0;

	virtual void
	cancel () override = 0;

	virtual ~T () = default;
};
