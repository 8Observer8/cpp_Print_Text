
#include <stdexcept>
#include <string>
#include <iostream>

class LogicError : public std::logic_error {
public:

    LogicError( ) : std::logic_error( "" ) {

    }

    virtual const char *what( ) const throw( ) {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw( ) {

    }

protected:
    std::string m_message;
};

class EmptyArgument : public LogicError {
public:

    EmptyArgument( ) {
        m_message = "Error: empty argument";
    }
};

void printText( const std::string &text ) throw( EmptyArgument ) {

    if( text.empty( ) ) {
        throw EmptyArgument( );
    }

    std::cout << text << std::endl;
}

int main() {
    std::string text = "Hello, World!";

    try {
        printText( text );
    } catch( const LogicError &e ) {
        std::cerr << e.what() << std::endl;
    } catch( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
    }

    return 0;
}
