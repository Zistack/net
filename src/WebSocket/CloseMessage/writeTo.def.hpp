template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	if (this -> m_status_code != 1005)
	{
		IO::Rule::putIntType <decltype (this -> m_status_code)>
		(
			this -> m_status_code,
			std::forward <OutputStream> (output_stream)
		);

		if (this -> m_reason)
		{
			output_stream . print (* this -> m_reason);
		}
	}
}
