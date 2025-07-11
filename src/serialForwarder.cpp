#include "serialForwarder.h"

CSerialForwarder::CSerialForwarder(uint16_t uiPort)
    :   m_server( uiPort )
{
}

CSerialForwarder::~CSerialForwarder()
{
}

void CSerialForwarder::Setup()
{
	m_server.begin();
}

bool CSerialForwarder::Loop(SoftwareSerial &strm)
{
    bool bResult = false;
    if ( m_server.hasClient() )
    {
        if ( m_client )
            m_client.stop(); // if new client connects, kick the old one.

        m_client = m_server.accept();
    }

    if ( m_client && m_client.connected( ))
    {
        bResult = true;
		while( m_client.available()) 
        {
            uint8_t data = m_client.read();
	  		strm.write( data );
 //           m_client.write( data );
		}

        while( strm.available() )
        {
            m_client.write( strm.read() );    
        }
    }
    return bResult;
}
