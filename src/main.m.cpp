// main.m.cpp

#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace std ;

namespace {

void init_logger()
{
  try {
    auto file_logger = spdlog::basic_logger_mt( "MAIN", "logs/test.txt" ) ;
    spdlog::set_default_logger( file_logger ) ;
  }
  catch ( const spdlog::spdlog_ex &e )
  {
    cout << e.what() << "\n" ;
  }
}

} // close anonymous namespace

int main( int argc, char* argv[] )
{
  init_logger() ;

  spdlog::info( "Hello World" ) ;
  cout << "Hello World\n" ;
  return 0 ;
}
