#ifndef JSON_HPP
#define JSON_HPP

#include "./json/include.hpp"

namespace JSON {
  
  namespace Number {
    
#   include "./json/number/type.hpp"
    
  }
  namespace String {
    
    
  }
  namespace Error {
    
#   include "./json/error/type.hpp"
    
  }
  namespace SyntaxError {
    
#   include "./json/syntaxerror/type.hpp"
    
  }
  namespace Integer {
    
    
  }
  namespace Object {
    
    
  }
  
}

namespace JSON {
  
  namespace Number {
    
    
  }
  namespace String {
    
    
  }
  namespace Error {
    
#   include "./json/error/not_a_string.hpp"
#   include "./json/error/none.hpp"
#   include "./json/error/invalid_character.hpp"
#   include "./json/error/unexpected_format.hpp"
#   include "./json/error/unexpected_eof.hpp"
#   include "./json/error/invalid_code_point.hpp"
    
  }
  namespace SyntaxError {
    
    
  }
  namespace Integer {
    
    
  }
  namespace Object {
    
    
  }
  
}

namespace JSON {
  
  namespace Number {
    
#   include "./json/number/struct.hpp"
    
  }
  namespace String {
    
    
  }
  namespace Error {
    
    
  }
  namespace SyntaxError {
    
#   include "./json/syntaxerror/struct.hpp"
    
  }
  namespace Integer {
    
    
  }
  namespace Object {
    
    
  }
  
}

namespace JSON {
  
  namespace Number {
    
    void
    deserialize (T * number, std::istream * json_stream);
    void
    setExponent (T * number, std::string exponent);
    void
    clean (T * number);
    void
    destroy (T * number);
    void
    init (T * number, std::string base);
    T *
    create (std::string base);
    Error::T
    serialize (T * number, std::ostream * json_stream);
    void
    setMantissa (T * number, std::string mantissa);
    
  }
  namespace String {
    
    Error::T
    deserialize (std::istream * json_stream, std::string * value);
    Error::T
    getCodePoint (std::istream * json_stream, uint16_t * cp);
    Error::T
    encode (char c, std::ostream * json_stream);
    char
    nibbleToChar (uint8_t nibble);
    Error::T
    serialize (std::string * value, std::ostream * json_stream);
    Error::T
    decode (std::istream * json_stream, std::string * value);
    
  }
  namespace Error {
    
    
  }
  namespace SyntaxError {
    
    void
    clean (T * syntax_error);
    void
    destroy (T * syntax_error);
    void
    init (T * syntax_error);
    T *
    create ();
    
  }
  namespace Integer {
    
    Error::T
    deserialize (std::istream * json_stream,
        unsigned int decimal_places,
        mpz_class * value);
    Error::T
    serialize (mpz_class * value,
        unsigned int decimal_places,
        std::ostream * json_stream);
    
  }
  namespace Object {
    
    Error::T
    nameSeparator (std::istream * json_stream);
    Error::T
    open (std::istream * json_stream);
    Error::T
    close (std::istream * json_stream);
    Error::T
    valueSeparator (std::istream * json_stream);
    
  }
  bool
  closer (std::char_traits<char>::int_type c);
  void
  skipWhitespace (std::istream * json_stream);
  bool
  terminal (std::char_traits<char>::int_type c);
  bool
  digit (std::char_traits<char>::int_type c);
  bool
  eof (std::char_traits<char>::int_type c);
  bool
  whitespace (std::char_traits<char>::int_type c);
  
}

namespace JSON {
  
  namespace Number {
    
#   include "./json/number/deserialize.hpp"
#   include "./json/number/setexponent.hpp"
#   include "./json/number/clean.hpp"
#   include "./json/number/destroy.hpp"
#   include "./json/number/init.hpp"
#   include "./json/number/create.hpp"
#   include "./json/number/serialize.hpp"
#   include "./json/number/setmantissa.hpp"
    
  }
  namespace String {
    
#   include "./json/string/deserialize.hpp"
#   include "./json/string/getcodepoint.hpp"
#   include "./json/string/encode.hpp"
#   include "./json/string/nibbletochar.hpp"
#   include "./json/string/serialize.hpp"
#   include "./json/string/decode.hpp"
    
  }
  namespace Error {
    
    
  }
  namespace SyntaxError {
    
#   include "./json/syntaxerror/clean.hpp"
#   include "./json/syntaxerror/destroy.hpp"
#   include "./json/syntaxerror/init.hpp"
#   include "./json/syntaxerror/create.hpp"
    
  }
  namespace Integer {
    
#   include "./json/integer/deserialize.hpp"
#   include "./json/integer/serialize.hpp"
    
  }
  namespace Object {
    
#   include "./json/object/nameseparator.hpp"
#   include "./json/object/open.hpp"
#   include "./json/object/close.hpp"
#   include "./json/object/valueseparator.hpp"
    
  }
# include "./json/closer.hpp"
# include "./json/skipwhitespace.hpp"
# include "./json/terminal.hpp"
# include "./json/digit.hpp"
# include "./json/eof.hpp"
# include "./json/whitespace.hpp"
  
}

#endif /* JSON_HPP */
