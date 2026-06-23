#ifndef __serialforwarder_h__
#define __serialforwarder_h__

#include <ESP8266WiFi.h>
#include "SoftwareSerial.h"

class CSerialForwarder
{
    private:
        WiFiServer m_server;
        WiFiClient m_client;
    public:
        CSerialForwarder( uint16_t uiPort );
        virtual ~CSerialForwarder();
        void Setup();
        bool Loop( SoftwareSerial& strm );
 };

#endif
