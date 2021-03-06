template <typename InputStream, typename Stage, typename OutputStream>
void
T <InputStream, Stage, OutputStream>::cancel ()
{
	if constexpr (Failure::IsCancellable::T <InputStream>::value)
	{
		this -> m_input_stream . cancel ();
	}

	if constexpr (Failure::IsCancellable::T <OutputStream>::value)
	{
		this -> m_output_stream . cancel ();
	}
}
