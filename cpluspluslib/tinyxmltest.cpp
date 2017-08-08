#include "tinyxmltest.h"

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"

using namespace std;

bool MyTinyXML::SaveFile(TiXmlDocument *doc, const char *filename)
{
    if(nullptr == doc || !doc->SaveFile(filename))
    {
        cerr << "MyTinyXML::SaveFile " << filename << " failed!" << endl;
        return false;
    }
    return true;
}

bool MyTinyXML::LoadFile(TiXmlDocument *doc, TiXmlEncoding encoding)
{
    if(nullptr == doc || !doc->LoadFile(encoding))
    {
        cerr << "MyTinyXML::LoadFile failed!" << endl;
        return false;
    }
    return true;
}

bool MyTinyXML::LoadFile(const char *filename)
{
    TiXmlDocument *doc = new TiXmlDocument(filename); //create a XML DOC object
    return LoadFile(doc);
}

TiXmlNode *MyTinyXML::LinkEndChild(TiXmlNode *addTo, TiXmlNode *addThis)
{
    TiXmlNode *node = addTo->LinkEndChild(addThis);
    if(nullptr == node)
        throw std::bad_exception();
    return node;
}

TiXmlElement *MyTinyXML::FirstChildElement(TiXmlElement *node)
{
    if(nullptr == node)
        throw std::bad_exception();
    return node->FirstChildElement();
}

TiXmlElement *MyTinyXML::RootElement(TiXmlDocument *doc)
{
    TiXmlElement *root = doc->RootElement();
    if(nullptr == root)
        throw std::bad_exception();
    return root;
}

TiXmlElement *MyTinyXML::NextSiblingElement(TiXmlElement *node)
{
    TiXmlElement *sib = node->NextSiblingElement();
    if(nullptr == sib)
        throw std::bad_exception();
    return sib;
}

TiXmlAttribute *MyTinyXML::FirstAttribute(TiXmlElement *node)
{
    TiXmlAttribute *attr = node->FirstAttribute();
    if(nullptr == attr)
        throw std::bad_exception();
    return attr;
}

using namespace MyTinyXML;

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
        LinkEndChild(doc, dec);
        TiXmlElement *rootelem = new TiXmlElement("GbsipConfig"); //create a root element
        LinkEndChild(doc, rootelem); //create link

        TiXmlElement *clientelem = new TiXmlElement("Client"); //create a child element and link it to root element
        LinkEndChild(rootelem, clientelem);
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
        LinkEndChild(clientelem, localipelem);
        LinkEndChild(clientelem, localportelem);
        LinkEndChild(clientelem, serveridelem);
        LinkEndChild(clientelem, serverdomainelem);
        LinkEndChild(clientelem, serveripelem);
        LinkEndChild(clientelem, serverportelem);
        LinkEndChild(clientelem, userauthidelem);
        LinkEndChild(clientelem, userauthpasswordelem);
        LinkEndChild(clientelem, registerperiodelem);
        LinkEndChild(clientelem, heartcycleelem);
        LinkEndChild(clientelem, hearttimeoutelem);
        LinkEndChild(clientelem, intervalelem);

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
        LinkEndChild(localipelem, localiptext);
        LinkEndChild(localportelem, localporttext);
        LinkEndChild(serveridelem, serveridtext);
        LinkEndChild(serverdomainelem, serverdomaintext);
        LinkEndChild(serveripelem, serveriptext);
        LinkEndChild(serverportelem, serverporttext);
        LinkEndChild(userauthidelem, userauthidtext);
        LinkEndChild(userauthpasswordelem, userauthpasswordtext);
        LinkEndChild(registerperiodelem, registerperiodtext);
        LinkEndChild(heartcycleelem, heartcycletext);
        LinkEndChild(hearttimeoutelem, hearttimeouttext);
        LinkEndChild(intervalelem, intervaltext);

        TiXmlElement *childelem = new TiXmlElement("sipchannel"); //create a child element
        LinkEndChild(clientelem, childelem); //create link
        childelem->SetAttribute("ID", "1"); //set attribute
        TiXmlElement *channelidelem = new TiXmlElement("channelid");
        LinkEndChild(childelem, channelidelem);
        TiXmlText *channelidtext = new TiXmlText("34020000001310000001");
        LinkEndChild(channelidelem, channelidtext);

        TiXmlElement *childelem2 = new TiXmlElement("sipchannel"); //create a child element
        LinkEndChild(clientelem, childelem2); //create link
        childelem2->SetAttribute("ID", "2"); //set attribute
        TiXmlElement *channelidelem2 = new TiXmlElement("channelid");
        LinkEndChild(childelem2, channelidelem2);
        TiXmlText *channelidtext2 = new TiXmlText("34020000001310000002");
        LinkEndChild(channelidelem2, channelidtext2);

        return SaveFile(doc, filename.c_str());
    }
    catch(bad_exception& err)
    {
        cerr << "err is " << err.what() << endl;
        return false;
    }
    return true;
}

bool TinyXMLTest::ReadXmlFile(string filename)
{
    try
    {
        TiXmlDocument *doc = new TiXmlDocument(filename.c_str()); //create a XML DOC object
        if(!LoadFile(doc))
        {
            return false;
        }
//        doc->Print(); //print document content
        TiXmlElement *rootelem = RootElement(doc); //get root element
        cout << rootelem->Value() << endl; //root element name

        TiXmlElement *clientelem = FirstChildElement(rootelem); //get client element, namely first child
        TiXmlElement *localipelem = FirstChildElement(clientelem);
        TiXmlElement *localportelem = NextSiblingElement(localipelem);
        TiXmlElement *serveridelem = NextSiblingElement(localportelem);
        TiXmlElement *serverdomainelem = NextSiblingElement(serveridelem);
        TiXmlElement *serveripelem = NextSiblingElement(serverdomainelem);
        TiXmlElement *serverportelem = NextSiblingElement(serveripelem);
        TiXmlElement *userauthidelem = NextSiblingElement(serverportelem);
        TiXmlElement *userauthpasswordelem = NextSiblingElement(userauthidelem);
        TiXmlElement *registerperiodelem = NextSiblingElement(userauthpasswordelem);
        TiXmlElement *heartcycleelem = NextSiblingElement(registerperiodelem);
        TiXmlElement *hearttimeoutelem = NextSiblingElement(heartcycleelem);
        TiXmlElement *intervalelem = NextSiblingElement(hearttimeoutelem);
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

        TiXmlElement *childelem = NextSiblingElement(intervalelem);
        TiXmlAttribute *channelidattr = FirstAttribute(childelem);
        TiXmlElement *channelidelem = FirstChildElement(childelem);
        cout << "sipchannel_ID--" << channelidattr->Name() << "\t" << channelidattr->Value() << endl;
        cout << "sipchannel_channelid--" << channelidelem->Value() << "\t" << channelidelem->GetText() << endl;

        TiXmlElement *childelem2 = NextSiblingElement(childelem);
        TiXmlAttribute *channelidattr2 = FirstAttribute(childelem2);
        TiXmlElement *channelidelem2 = FirstChildElement(childelem2);
        cout << "sipchannel_ID--" << channelidattr2->Name() << "\t" << channelidattr2->Value() << endl;
        cout << "sipchannel_channelid--" << channelidelem2->Value() << "\t" << channelidelem2->GetText() << endl;

        // test exception
        TiXmlElement *childelem3 = NextSiblingElement(childelem2);
        TiXmlAttribute *channelidattr3 = FirstAttribute(childelem3);
        TiXmlElement *channelidelem3 = FirstChildElement(childelem3);
        cout << "sipchannel_ID--" << channelidattr3->Name() << "\t" << channelidattr3->Value() << endl;
        cout << "sipchannel_channelid--" << channelidelem3->Value() << "\t" << channelidelem3->GetText() << endl;

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
    catch(bad_exception& err)
    {
        cerr << "TinyXMLTest::ReadXmlFile--catch exception, filename is " << filename << ";err is "  << err.what() << endl;
        return false;
    }
    return true;
}
