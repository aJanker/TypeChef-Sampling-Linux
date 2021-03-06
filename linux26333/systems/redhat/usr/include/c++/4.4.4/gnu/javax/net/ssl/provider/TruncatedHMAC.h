
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_TruncatedHMAC__
#define __gnu_javax_net_ssl_provider_TruncatedHMAC__

#pragma interface

#include <gnu/javax/net/ssl/provider/Extension$Value.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
          namespace provider
          {
              class TruncatedHMAC;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
    }
  }
}

class gnu::javax::net::ssl::provider::TruncatedHMAC : public ::gnu::javax::net::ssl::provider::Extension$Value
{

public:
  TruncatedHMAC();
  virtual jint length();
  virtual ::java::nio::ByteBuffer * buffer();
  virtual ::java::lang::String * toString();
  virtual ::java::lang::String * toString(::java::lang::String *);
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_TruncatedHMAC__
