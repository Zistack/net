struct T : IO::Interface::ClientSocket::T
{
	T (const NullableString::T & hostname, const NullableString::T & port);
	T (const Config::T & config);
	T (JSON::Value::T * config_value);

	T (Server::T * server_socket);

	T (const T & other) = delete;

	IO::FileDescriptor::InputStream::T *
	inputStream () const override;
	IO::FileDescriptor::OutputStream::T *
	outputStream () const override;

	~T () override;

	private:
	int file_descriptor;

	IO::FileDescriptor::InputStream::T * input_stream;
	IO::FileDescriptor::OutputStream::T * output_stream;
};
