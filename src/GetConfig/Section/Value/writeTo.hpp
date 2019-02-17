template <typename ValueType, const Spec::T & spec>
void
T<ValueType, spec>::writeTo (IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	output_stream.print ("{\n");

	for (auto [identifier, member] : this->members)
	{
		IO::Util::indent (output_stream, indentation + 1);

		if (member.value)
		{
			output_stream.print ("set ");
			Rule::putIdentifier (identifier, output_stream);
			output_stream.put (' ');
			member.type->writeTo (
			    *member.value, output_stream, indentation + 1);
		}
		else
		{
			output_stream.print ("unset ");
			Rule::putIdentifier (identifier, output_stream);
		}

		output_stream.put ('\n');
	}

	IO::Util::indent (output_stream, indentation);
	output_stream.put ('}');
}
