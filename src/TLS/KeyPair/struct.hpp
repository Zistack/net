struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setCertificateFilename (const std::string & certificate_filename);

	std::string
	getCertificateFilename () const;

	void
	setPrivateKeyFilename (const std::string & private_key_filename);

	std::string
	getPrivateKeyFilename () const;
};
