T::T (char short_form,
    std::function<void(void)> flagAction,
    std::string description) :
    short_form (short_form),
    long_form (""),
    flagAction (flagAction),
    argAction (nullptr),
    description (description)
{
}

T::T (char short_form,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form (short_form),
    long_form (""),
    flagAction (nullptr),
    argAction (argAction),
    description (description)
{
}

T::T (char short_form,
    std::function<void(void)> flagAction,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form (short_form),
    long_form (""),
    flagAction (flagAction),
    argAction (argAction),
    description (description)
{
}

T::T (std::string long_form,
    std::function<void(void)> flagAction,
    std::string description) :
    short_form ('\0'),
    long_form (long_form),
    flagAction (flagAction),
    argAction (nullptr),
    description (description)
{
}

T::T (std::string long_form,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form ('\0'),
    long_form (long_form),
    flagAction (nullptr),
    argAction (argAction),
    description (description)
{
}

T::T (std::string long_form,
    std::function<void(void)> flagAction,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form ('\0'),
    long_form (long_form),
    flagAction (flagAction),
    argAction (argAction),
    description (description)
{
}

T::T (char short_form,
    std::string long_form,
    std::function<void(void)> flagAction,
    std::string description) :
    short_form (short_form),
    long_form (long_form),
    flagAction (flagAction),
    argAction (nullptr),
    description (description)
{
}

T::T (char short_form,
    std::string long_form,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form (short_form),
    long_form (long_form),
    flagAction (nullptr),
    argAction (argAction),
    description (description)
{
}

T::T (char short_form,
    std::string long_form,
    std::function<void(void)> flagAction,
    std::function<void(char *)> argAction,
    std::string description) :
    short_form (short_form),
    long_form (long_form),
    flagAction (flagAction),
    argAction (argAction),
    description (description)
{
}
