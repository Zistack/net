template <typename ValueType, const Spec::T & spec>
void
T<ValueType, spec>::readFrom (
    IO::Interface::PeekableInputStream::T & input_stream)
{
	try
	{
		IO::Util::expect (input_stream, '{');

		Util::skipWhitespace (input_stream);

		while (!IO::Util::test (input_stream, '}'))
		{
			std::string op = Rule::getOp (input_stream);

			if (op == "set")
			{
				Util::skipWhitespace (input_stream);

				std::string identifier = Rule::getIdentifier (input_stream);

				if (!this->members.count (identifier))
				{
					throw Failure::SyntaxError::T (
					    "Unrecognized member identifier '" + identifier +
					    "'\n");
				}

				Util::skipWhitespace (input_stream);

				Member::T & member = this->members.at (identifier);
				member.value = member.type->readFrom (input_stream);

				Util::skipWhitespace (input_stream);
			}
			else if (op == "unset")
			{
				Util::skipWhitespace (input_stream);

				std::string identifier = Rule::getIdentifier (input_stream);

				if (!this->members.count (identifier))
				{
					throw Failure::SyntaxError::T (
					    "Unrecognized member identifier '" + identifier +
					    "'\n");
				}

				Member::T & member = this->members.at (identifier);
				member.value = nullptr;

				Util::skipWhitespace (input_stream);
			}
			else
			{
				throw Failure::SyntaxError::T (
				    "Unrecognized operator '" + op + "'\n");
			}
		}
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
