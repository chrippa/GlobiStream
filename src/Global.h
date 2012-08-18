#ifndef GLOBAL_H
#define GLOBAL_H

#include <QStringList>
#include <QSize>
#include <QColor>

struct Stream
{
    QString name;
    QString url;
    bool online;
    QStringList qualities;

    Stream(const QString & _name, const QString & _url) : 
        name(_name), url(_url), online(false) { }
};

typedef QList <Stream> StreamList;

/* Network */
static const QString DEFAULT_HOST_ADDRESS("83.152.208.202");
static const quint16 DEFAULT_HOST_PORT(1337);

enum PacketType
{
    StreamsUpdate // StreamList
};

/* LiveStreamer */
static const QString LIVE_STREAMER_PATH("C:\\Python27\\Lib\\site-packages\\livestreamer-1.1.0-py2.7.egg");
static const QString POLLING_COMMAND("livestreamer %1 & exit\n");
static const QString START_LIVESTREAMER_COMMAND("livestreamer %1 %2 --player \"\\\"%3\\\"\"\n");
static const QString OUTPUT_QUALITIES_LINE_BEGIN("Found streams: ");
static const QString QUALITIES_SEPARATOR(", ");

/* MS-DOS */
static const QString WINDOWS_CMD_PROCESS("cmd");
static const QString CHANGE_DIRECTORY_COMMAND("cd \"%1\"\n");
static const QString EXIT_COMMAND("exit\n");
static const int EXIT_TIMEOUT(200);

/* GUI */
static const QString APPLICATION_ICON(":/GlobiStreams/Icon");
static const QColor ONLINE_COLOR("lime");
static const QColor OFFLINE_COLOR("red");
static const int MINIMUM_TABLE_SECTION_SIZE(50);

/* Cache */
static const QString PROJECT_NAME("GlobiStream");
static const QString CACHE_KEY_PLAYER_PATH("MediaPlayer"); // -> QString
static const QString DEFAULT_PLAYER_PATH("C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe");
static const QString CACHE_KEY_COOKIES("Cookies");
static const QString CACHE_COOKIES_NAME_VALUE_SPEARATOR("|||");
static const QString CACHE_COOKIES_SEPARATOR(";;;");

/* Twitch specific */
static const QString TWITCH_CHAT_URL_EXTENSION("/chat/embed?channel=%1&popout_chat=true");
static const QSize TWITCH_CHAT_MINIMUM_SIZE(250, 330);

/* Displayed strings */
static const QString ONLINE_STATE("Online");
static const QString OFFLINE_STATE("Offline");
static const QString URL_RICH_TEXT_TEMPLATE("<a href=\"%1\">%1</a>");
static const QString NEW_ONLINE_STREAMS_TITLE("Wut");
static const QString NEW_ONLINE_STREAMS_NOTIFICATION("New streams are now live :\n%1");
static const QString CONNECTED_TO_HOST("Connected to \"%1:%2\"");
static const QString LOST_CONNECTION("Lost connection to server");

QStringList parseQualitiesFromOutput(const QString & output, bool & online);
QString twitchChatFromUrl(const QString & url);
bool operator==(const Stream & lValue, const Stream & rValue);

#endif // GLOBAL_H