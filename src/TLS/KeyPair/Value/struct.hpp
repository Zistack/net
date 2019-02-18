struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setCertificateFilename (const std::string & certificate_filename);

	std::string
	getCertificateFilename () const;

	void
	setPrivateKeyFilename (const std::string & private_key_filename);

	std::string
	getPrivateKeyFilename () const;
};
