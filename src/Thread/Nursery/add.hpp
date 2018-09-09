void
T::add (std::function<void(void)> run)
{
	this->add (run, nullptr, nullptr);
}

void
T::add (std::function<void(void)> run, std::function<void(void)> cancel)
{
	this->add (run, nullptr, cancel);
}

void
T::add (std::function<void(void)> run,
    std::function<void(void)> clean,
    std::function<void(void)> cancel)
{
	this->start (
	    [run, clean, this]() {
		    bool first_fail = false;
		    try
		    {
			    run ();
		    }
		    catch (...)
		    {
			    first_fail =
			        this->exception_store.store (std::current_exception ());
		    }
		    this->finish ();
		    if (first_fail) this->cancel ();
		    if (clean) clean ();
	    },
	    cancel);
}
