void
T::validate (bool partial_message) const
{
	if (this->isControl ())
	{
		if (this->payload_length > 125)
		{
			throw Failure::SemanticError::T (
			    "Control frames may not have a payload of more than "
			    "125 bytes\n");
		}

		if (!this->final_frame)
		{
			throw Failure::SemanticError::T (
			    "Control frames may not have fragmented payloads\n");
		}
	}
	else if (this->isMessage ())
	{
		if (partial_message)
		{
			throw Failure::SemanticError::T (
			    "Must finish previous message before starting a new "
			    "one\n");
		}
	}
	else if (this->opcode == Type::CONTINUATION)
	{
		if (!partial_message)
		{
			throw Failure::SemanticError::T (
			    "Must start a message before continuing one\n");
		}
	}
	else
	{
		throw Failure::SemanticError::T ("Cannot interpret unknown opcode\n");
	}
}
