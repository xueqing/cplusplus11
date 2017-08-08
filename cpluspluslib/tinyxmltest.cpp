#include "tinyxmltest.h"

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

using namespace std;

TinyXMLTest::TinyXMLTest()
{
    TestLib();
}

TinyXMLTest::~TinyXMLTest()
{

}

void TinyXMLTest::TestLib()
{
    string filename("./ewardsipconfig.xml");
    WriteXmlFile(filename);
    ReadXmlFile(filename);
}

bool TinyXMLTest::WriteXmlFile(string filename)
{
    try
    {
        TiXmlDocument *doc = new TiXmlDocument; //create a XML DOC object
        TiXmlDeclaration *dec = new TiXmlDeclaration("1.0", "", "");
        doc->LinkEndChild(dec);
        TiXmlElement *rootelem = new TiXmlElement("GbsipConfig"); //create a root element
        doc->LinkEndChild(rootelem); //create link

        TiXmlElement *clientelem = new TiXmlElement("Client"); //create a child element and link it to root element
        rootelem->LinkEndChild(clientelem);
        TiXmlElement *localipelem = new TiXmlElement("localip");//create other element and link them to client element
        TiXmlElement *localportelem = new TiXmlElement("localport");
        TiXmlElement *serveridelem = new TiXmlElement("serverid");
        TiXmlElement *serverdomainelem = new TiXmlElement("serverdomain");
        TiXmlElement *serveripelem = new TiXmlElement("serverip");
        TiXmlElement *serverportelem = new TiXmlElement("serverport");
        TiXmlElement *userauthidelem = new TiXmlElement("userauthid");
        TiXmlElement *userauthpasswordelem = new TiXmlElement("userauthpassword");
        TiXmlElement *registerperiodelem = new TiXmlElement("registerperiod");
        TiXmlElement *heartcycleelem = new TiXmlElement("heartcycle");
        TiXmlElement *hearttimeoutelem = new TiXmlElement("hearttimeout");
        TiXmlElement *intervalelem = new TiXmlElement("interval");
        clientelem->LinkEndChild(localipelem);
        clientelem->LinkEndChild(localportelem);
        clientelem->LinkEndChild(serveridelem);
        clientelem->LinkEndChild(serverdomainelem);
        clientelem->LinkEndChild(serveripelem);
        clientelem->LinkEndChild(serverportelem);
        clientelem->LinkEndChild(userauthidelem);
        clientelem->LinkEndChild(userauthpasswordelem);
        clientelem->LinkEndChild(registerperiodelem);
        clientelem->LinkEndChild(heartcycleelem);
        clientelem->LinkEndChild(hearttimeoutelem);
        clientelem->LinkEndChild(intervalelem);

        TiXmlText *localiptext = new TiXmlText("localhost");//set content for elements
        TiXmlText *localporttext = new TiXmlText("5062");
        TiXmlText *serveridtext = new TiXmlText("34020000002000000001");
        TiXmlText *serverdomaintext = new TiXmlText("3402000000");
        TiXmlText *serveriptext = new TiXmlText("192.168.1.111");
        TiXmlText *serverporttext = new TiXmlText("5060");
        TiXmlText *userauthidtext = new TiXmlText("34020000001110000001");
        TiXmlText *userauthpasswordtext = new TiXmlText("12345678");
        TiXmlText *registerperiodtext = new TiXmlText("3600");
        TiXmlText *heartcycletext = new TiXmlText("20");
        TiXmlText *hearttimeouttext = new TiXmlText("3");
        TiXmlText *intervaltext = new TiXmlText("10");
        localipelem->LinkEndChild(localiptext);
        localportelem->LinkEndChild(localporttext);
        serveridelem->LinkEndChild(serveridtext);
        serverdomainelem->LinkEndChild(serverdomaintext);
        serveripelem->LinkEndChild(serveriptext);
        serverportelem->LinkEndChild(serverporttext);
        userauthidelem->LinkEndChild(userauthidtext);
        userauthpasswordelem->LinkEndChild(userauthpasswordtext);
        registerperiodelem->LinkEndChild(registerperiodtext);
        heartcycleelem->LinkEndChild(heartcycletext);
        hearttimeoutelem->LinkEndChild(hearttimeouttext);
        intervalelem->LinkEndChild(intervaltext);

        TiXmlElement *childelem = new TiXmlElement("sipchannel"); //create a child element
        clientelem->LinkEndChild(childelem); //create link
        childelem->SetAttribute("ID", "1"); //set attribute
        TiXmlElement *channelidelem = new TiXmlElement("channelid");
        childelem->LinkEndChild(channelidelem);
        TiXmlText *channelidtext = new TiXmlText("34020000001310000001");
        channelidelem->LinkEndChild(channelidtext);

        TiXmlElement *childelem2 = new TiXmlElement("sipchannel"); //create a child element
        clientelem->LinkEndChild(childelem2); //create link
        childelem2->SetAttribute("ID", "2"); //set attribute
        TiXmlElement *channelidelem2 = new TiXmlElement("channelid");
        childelem2->LinkEndChild(channelidelem2);
        TiXmlText *channelidtext2 = new TiXmlText("34020000001310000002");
        channelidelem2->LinkEndChild(channelidtext2);

        if(!doc->SaveFile(filename.c_str()))
        {
            cerr << "TinyXMLTest::WriteXmlFile--SaveFile " << filename << " failed!" << endl;
            return false;
        }
    }
    catch(...)
    {
        cerr << "TinyXMLTest::WriteXmlFile--catch exception, filename is " << filename << endl;
        return false;
    }
    return true;
}

bool TinyXMLTest::ReadXmlFile(string filename)
{
    try
    {
        TiXmlDocument *doc = new TiXmlDocument(filename.c_str()); //create a XML DOC object
        if(!doc->LoadFile())
        {
            cerr << "TinyXMLTest::ReadXmlFile--LoadFile " << filename << " failed!" << endl;
            return false;
        }
//        doc->Print(); //print document content
        TiXmlElement *rootelem = doc->RootElement(); //get root element
        cout << rootelem->Value() << endl; //root element name

        TiXmlElement *clientelem = rootelem->FirstChildElement(); //get client element, namely first child
        TiXmlElement *localipelem = clientelem->FirstChildElement();
        TiXmlElement *localportelem = localipelem->NextSiblingElement();
        TiXmlElement *serveridelem = localportelem->NextSiblingElement();
        TiXmlElement *serverdomainelem = serveridelem->NextSiblingElement();
        TiXmlElement *serveripelem = serverdomainelem->NextSiblingElement();
        TiXmlElement *serverportelem = serveripelem->NextSiblingElement();
        TiXmlElement *userauthidelem = serverportelem->NextSiblingElement();
        TiXmlElement *userauthpasswordelem = userauthidelem->NextSiblingElement();
        TiXmlElement *registerperiodelem = userauthpasswordelem->NextSiblingElement();
        TiXmlElement *heartcycleelem = registerperiodelem->NextSiblingElement();
        TiXmlElement *hearttimeoutelem = heartcycleelem->NextSiblingElement();
        TiXmlElement *intervalelem = hearttimeoutelem->NextSiblingElement();
        cout << "localip--" << localipelem->Value() << "\t" << localipelem->GetText() << endl;
        cout << "localport--" << localportelem->Value() << "\t" << localportelem->GetText() << endl;
        cout << "serverid--" << serveridelem->Value() << "\t" << serveridelem->GetText() << endl;
        cout << "serverdomain--" << serverdomainelem->Value() << "\t" << serverdomainelem->GetText() << endl;
        cout << "serverip--" << serveripelem->Value() << "\t" << serveripelem->GetText() << endl;
        cout << "serverport--" << serverportelem->Value() << "\t" << serverportelem->GetText() << endl;
        cout << "userauthid--" << userauthidelem->Value() << "\t" << userauthidelem->GetText() << endl;
        cout << "userauthpassword--" << userauthpasswordelem->Value() << "\t" << userauthpasswordelem->GetText() << endl;
        cout << "registerperiod--" << registerperiodelem->Value() << "\t" << registerperiodelem->GetText() << endl;
        cout << "heartcycle--" << heartcycleelem->Value() << "\t" << heartcycleelem->GetText() << endl;
        cout << "hearttimeout--" << hearttimeoutelem->Value() << "\t" << hearttimeoutelem->GetText() << endl;
        cout << "interval--" << intervalelem->Value() << "\t" << intervalelem->GetText() << endl;

        TiXmlElement *childelem = intervalelem->NextSiblingElement();
        TiXmlAttribute *channelidattr = childelem->FirstAttribute();
        TiXmlElement *channelidelem = childelem->FirstChildElement();
        cout << "sipchannel_ID--" << channelidattr->Name() << "\t" << channelidattr->Value() << endl;
        cout << "sipchannel_channelid--" << channelidelem->Value() << "\t" << channelidelem->GetText() << endl;

        TiXmlElement *childelem2 = childelem->NextSiblingElement();
        TiXmlAttribute *channelidattr2 = childelem2->FirstAttribute();
        TiXmlElement *channelidelem2 = childelem2->FirstChildElement();
        cout << "sipchannel_ID--" << channelidattr2->Name() << "\t" << channelidattr2->Value() << endl;
        cout << "sipchannel_channelid--" << channelidelem2->Value() << "\t" << channelidelem2->GetText() << endl;

//        // test exception
//        TiXmlElement *childelem3 = childelem2->NextSiblingElement();
//        TiXmlAttribute *channelidattr3 = childelem3->FirstAttribute();
//        TiXmlElement *channelidelem3 = childelem3->FirstChildElement();
//        cout << "sipchannel_ID--" << channelidattr3->Name() << "\t" << channelidattr3->Value() << endl;
//        cout << "sipchannel_channelid--" << channelidelem3->Value() << "\t" << channelidelem3->GetText() << endl;

        SipConneciton sipconn;
        SipServer sipserver;
        SipChannel sipchann;
        vector<SipChannel> sipchanlist;

        sipconn.localIp = localipelem->GetText();
        sipconn.localPort = atoi(localportelem->GetText());
        sipconn.userAuthId = userauthidelem->GetText();
        sipconn.userAuthPassword = userauthpasswordelem->GetText();
        sipconn.validRegisterPeriod = atoi(registerperiodelem->GetText());
        sipconn.heartCycle = atoi(heartcycleelem->GetText());
        sipconn.maxHeartTimeout = atoi(hearttimeoutelem->GetText());
        sipconn.interval = atoi(intervalelem->GetText());

        sipserver.serverId = serveridelem->GetText();
        sipserver.serverDomain = serverdomainelem->GetText();
        sipserver.serverIp = serveripelem->GetText();
        sipserver.serverPort = atoi(serverportelem->GetText());

        sipchann.id = atoi(channelidattr->Value());
        sipchann.channelId = channelidelem->GetText();
        sipchanlist.push_back(sipchann);
        sipchann.id = atoi(channelidattr2->Value());
        sipchann.channelId = channelidelem2->GetText();
        sipchanlist.push_back(sipchann);
    }
    catch(exception& err)
    {
        cerr << "TinyXMLTest::ReadXmlFile--catch exception, filename is " << filename << ";err is "  << err.what() << endl;
        return false;
    }
    return true;
}
