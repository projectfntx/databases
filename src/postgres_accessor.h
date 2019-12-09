// postgres_accessor.h

#include <string>
#include <pqxx/pqxx>

using namespace std ;

namespace Fanatex {
namespace Postgres {

struct Credential
{
  string dbname ;
  string user ;
  string password ;
} ;

class Accessor
{
  public:

    Accessor( const Credential & cred ) ;

    ~Accessor() ;

  private:
    Credential        d_cred ;
    pqxx::connection  d_handle ;

} ;


} // close package namespace
} // close enterprise namespace