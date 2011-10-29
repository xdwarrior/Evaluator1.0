#include "libs/base.h"

char buff[MAXN], ch, *p, key[MAXLEN], value[MAXLEN];

string time_to_string(){
    time_t t = time( NULL );
    return string( asctime( localtime( &t ) ) );
}

void failure( string err_msg ){
    cout << err_msg << "!!!" << endl;
    clog << time_to_string << ": " << err_msg << "." << endl;
    exit( EXIT_FAILURE );
}

void load_defaults(){

}

int main(){

    /// Redirecting input, output & log
    {
        freopen( "./test-files/default.conf", "r", stdin );
        freopen( "./test-files/logfile.log", "w", stderr );
    }

    /// Load default settings
    load_defaults();

    /// Override default settings
	while( fgets( buff, MAXN, stdin ) != NULL ){
	    p = strchr( buff, '\n' );
	    if( p != 0 ) *p = '\0';

        if( buff[0] == '#' || ( buff[0] == '/' && buff[1] == '/' ) || !strlen( buff ) ) continue;

        sscanf( buff, "%[^=]%*[= ]%[^;]", key, value );
        key[strlen( key )-1] = '\0';

        Options[key] = value;
    }


    /// Testing for required settings

    if( !Options.count( "task_name" ) )
        failure( "Task name not specified" );
    if( !Options.count( "file_name" ) )
        failure( "Solution file name not specified" );



    /// Preproccessing settings
    for( O_ARRAY::iterator it = Options.begin(); it != Options.end(); ++it ){
        printf( "%s -> %s\n", it->first.c_str(), it->second.c_str() );

    }


    /// compiling file



	return EXIT_SUCCESS;
}
