struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	NullableString::T
	getHostname () const;

	void
	setHostname (const NullableString::T & hostname);

	NullableString::T
	getPort () const;

	void
	setPort (const NullableString::T & port);
};
