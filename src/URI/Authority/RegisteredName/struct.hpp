struct T : Host::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::string & registered_name);

	std::string
	toString () const override;

	std::unique_ptr<Host::T>
	clone () const override;

	~T () = default;

	private:
	std::string registered_name;
};
