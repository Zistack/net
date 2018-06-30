#ifndef TLS_HPP
#define TLS_HPP

#include "./include.hpp"

namespace TLS {
  
  namespace Config {
    
    namespace KeyPair {
      
#     include "./config/keypair/type.hpp"
      
    }
#   include "./config/type.hpp"
    
  }
  namespace Context {
    
#   include "./context/type.hpp"
    
  }
  
}

namespace TLS {
  
  namespace Config {
    
    namespace KeyPair {
      
      
    }
    
  }
  namespace Context {
    
#   include "./context/init.hpp"
    
  }
  
}

namespace TLS {
  
  namespace Config {
    
    namespace KeyPair {
      
#     include "./config/keypair/struct.hpp"
      
    }
#   include "./config/struct.hpp"
    
  }
  namespace Context {
    
#   include "./context/struct.hpp"
    
  }
  
}

namespace TLS {
  
  namespace Config {
    
    namespace KeyPair {
      
      void
      clean (T * key_pair);
      void
      destroy (T * key_pair);
      void
      init (T * key_pair,
          std::string * certificate_filename,
          std::string * private_key_filename);
      T *
      create (std::string * certificate_filename, std::string * private_key_filename);
      
    }
    void
    clean (T * config);
    void
    destroy (T * config);
    void
    init (T * config);
    T *
    create ();
    int
    parse (T * config, std::string config_filename);
    
  }
  namespace Context {
    
    void
    clean (T * context);
    void
    destroy (T * context);
    T *
    create (Config::T * config);
    
  }
  
}

namespace TLS {
  
  namespace Config {
    
    namespace KeyPair {
      
#     include "./config/keypair/clean.hpp"
#     include "./config/keypair/destroy.hpp"
#     include "./config/keypair/init.hpp"
#     include "./config/keypair/create.hpp"
      
    }
#   include "./config/clean.hpp"
#   include "./config/destroy.hpp"
#   include "./config/init.hpp"
#   include "./config/create.hpp"
#   include "./config/parse.hpp"
    
  }
  namespace Context {
    
#   include "./context/clean.hpp"
#   include "./context/destroy.hpp"
#   include "./context/create.hpp"
    
  }
# include "./init.hpp"
  
}

#endif /* TLS_HPP */
