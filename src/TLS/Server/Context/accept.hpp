std::unique_ptr<Connection::Context::T>
T::accept (IO::Interface::NonblockingInputStream::T & input,
    IO::Interface::NonblockingOutputStream::T & output)
{
	return std::make_unique<Connection::Context::T> (*this, input, output);
}
