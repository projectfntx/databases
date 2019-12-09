// postgres_accessor.cpp

#include "postgres_accessor.h"

#include <iostream>
#include <sstream>

namespace Fanatex {
namespace Postgres {

Accessor::Accessor( const Credential & cred )
    : d_cred( cred )
{
    try
    {
        stringstream ss ;
        ss << " dbname = "      << d_cred.dbname
           << " user = "        << d_cred.user
           << " password = "    << d_cred.password ;

        pqxx::connection d_handle( ss.str() ) ;

        if ( d_handle.is_open() )
        {
            cout << "db " << d_cred.dbname << " open\n" ;
            //spdlog::info( "Opened db" ) ;
        }
        else
        {
            cout << "could not open db " << d_cred.dbname.c_str() << "\n" ;
            //spdlog::info( "could not open db" ) ;
        }
    }
    catch ( const exception & e ) 
    {
        cout << e.what() << "\n" ;
        //spdlog::info( e.what() ) ;
    }
}

Accessor::~Accessor()
{
    d_handle.disconnect() ;
}

} // close package namespace
} // close enterprise namespace