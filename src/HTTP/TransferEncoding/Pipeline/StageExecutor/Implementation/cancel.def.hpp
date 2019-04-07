template <typename InputStream, typename Stage, typename OutputStream>
void
T <InputStream, Stage, OutputStream>::cancel ()
{
	if constexpr (Failure::TypeTraits::IsCancellable::T <InputStream>::value)
	{
		this -> input_stream . cancel ();
	}

	if constexpr (Failure::TypeTraits::IsCancellable::T <OutputStream>::value)
	{
		this -> output_stream . cancel ();
	}
}
