int
main (int argc, char ** argv)
{
	JSON::Number::T * number = JSON::Number::create ("100");

	JSON::Number::serialize (number, &std::cout);

	JSON::Number::destroy (number);

	std::cout << std::endl;

	mpz_class integer ("1234567890");

	JSON::Integer::serialize (&integer, 4, &std::cout);

	std::cout << std::endl;

	return 0;
}
