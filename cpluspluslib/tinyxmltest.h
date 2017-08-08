#ifndef TINYXMLTEST_H
#define TINYXMLTEST_H

#include <string>

#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"

//配置信息使用对象
enum ConfigUser
{
    FOR_LOCAL_USE, //0
    FOR_REMOTE_USE //1
};

//SIP客户端注册信息
struct SipConneciton
{
    int id;
    ConfigUser type;
    int serverConfigID;
    std::string localIp;
    int localPort;
    std::string userAuthId;
    std::string userAuthPassword;
    int validRegisterPeriod;
    int heartCycle;
    int maxHeartTimeout;
    int interval;
    int overrid;
    std::string status; //[kiki]"on""off"
};

//sip注册通道信息
struct SipChannel
{
    int id;
    int sipConnectionId;
    std::string channelId;
    std::string registerId;
    std::string name;
    std::string manufacturer;
    std::string model;
    std::string owner;
    std::string civilcode;
    std::string address;
    std::string parental;
    std::string parentId;
    std::string safetyway;
    std::string registerway;
    std::string secrecy;
    std::string status;
};

//sip服务端信息
struct SipServer
{
    int id;
    ConfigUser type;
    std::string serverDomain;
    std::string serverIp;
    std::string serverId;
    int serverPort;
};

namespace MyTinyXML {
    bool SaveFile(TiXmlDocument *doc, const char * filename);
    bool LoadFile(TiXmlDocument *doc, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);
    bool LoadFile(const char * filename);
    const char* Parse(TiXmlDocument *doc, const char* p, TiXmlParsingData* data = 0, TiXmlEncoding encoding = TIXML_DEFAULT_ENCODING);

    TiXmlNode* LinkEndChild(TiXmlNode* addTo, TiXmlNode* addThis);
    TiXmlNode* FirstChild(TiXmlElement* node);
    TiXmlNode* FirstChild(TiXmlElement* node, const char * _value);
    TiXmlNode* NextSibling(TiXmlNode *node);
    TiXmlElement* FirstChildElement(TiXmlElement* node);
    TiXmlElement* FirstChildElement(TiXmlElement* node, const char * _value);
    TiXmlElement* RootElement(TiXmlDocument* doc);
    TiXmlElement *NextSiblingElement(TiXmlElement* node);
    TiXmlAttribute* FirstAttribute(TiXmlElement* node);

    const char* GetText(TiXmlElement* node);
} //namespace MyTinyXML

class TinyXMLTest
{
public:
    TinyXMLTest();
    ~TinyXMLTest();

private:
    void TestLib();

    bool WriteXmlFile(std::string filename);
    bool ReadXmlFile(std::string filename);

    bool ParseXmlBody();
    bool ParseXmlBody(TiXmlDocument *doc);
    bool ParseXmlBody(const char *pbody);
};

#endif // TINYXMLTEST_H
